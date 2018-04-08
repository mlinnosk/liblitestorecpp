/**
 * Copyright (c) 2018 Markku Linnoskivi
 *
 * See the file LICENSE for copying permission.
 */
#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "litestore/litestore.h"

namespace lscpp
{
namespace detail
{
/**
 * This class is used as std::unique_ptr delete.
 */
struct LSDelete
{
    void operator()(litestore*) const;
};
using Handle = std::unique_ptr<::litestore, LSDelete>;
}

/**
 * RAII class for transactions.
 * 
 * A Transaction can only be constructed via Litestore class.
 * 
 * If the transaction is not commited or rollbacked explicitely
 * the destructor will ROLLBACK.
 */
class Transaction
{
    friend class Litestore;
public:
    enum class State { INITIAL, OPEN, DONE };
    /**
     * Destructor will rollback the transaction if it's not done.
     */
    ~Transaction() noexcept;
    Transaction(Transaction&& rhs) noexcept;
    Transaction(const Transaction&) = delete;
    Transaction& operator=(const Transaction&) = delete;
    Transaction& operator=(Transaction&&) = delete;
    /**
     * @return Current state of the transaction.
     */
    State state() const noexcept { return m_state; }
    /**
     * Commit the trasaction.
     * @throws std::runtime_error On failure.
     */
    void commit();
    /**
     * Rollback the transaction.
     * @throws std::runtime_error On failure.
     */
    void rollback();

private:
    Transaction(litestore* ls);

    litestore* m_litestore = nullptr;
    State m_state = State::INITIAL;
};

/**
 * The Litestore class is a RAII wrapper
 * for the Litestore C interface.
 * It provides the context management and
 * some what simpler API for CRUD operations. 
 */
class Litestore
{
public:
    using ErrorFunc = std::function<void(const int error, const char* desc)>;
    /**
     * Default constucted instance has no open handles to Litestore.
     */
    Litestore() = default;
    /**
     * Opens a handle to given Litestore instance.
     * @param filename The Litestore filename.
     */
    explicit Litestore(const char* filename);
    /**
     * Opens a handle to given Litestore instance.
     * @param filename The Litestore filename.
     * @param errFunc The error function that is called on errors.
     */
    Litestore(const char* filename, ErrorFunc errFunc);
    /**
     * Instance is non-copyable and non-assignable, but is movable.
     */
    Litestore(const Litestore&) = delete;
    Litestore(Litestore&&) = default;
    Litestore& operator=(const Litestore&) = delete;
    Litestore& operator=(Litestore&&) = default;
    /**
     * @return True if this instance has a valid handle to
     *         the Litestore.
     */
    bool is_open() const noexcept;
    /**
     * Explicitely close the handle to Litestore.
     */
    void close() noexcept;
    /**
     * Create a transaction.
     */
    Transaction createTx();
    /** CRUD API */
    /**
     * Create a blob with key.
     * The template type T must have valid specialization for 
     * BlobInput class.
     * 
     * @param key The key.
     * @param value Reference to the value to be stored.
     * @throws std::runtime_error if Operation fails or key exists.
     */
    template <typename T>
    void create(const std::string& key, const T& value);
    /**
     * Read a blob of type T with key.
     * The template type T must have valid specialization for 
     * BlobOutput class.
     * 
     * @param key The key.
     * @return The blob T.
     * @throws std::runtime_error if operation fails or key does not exist.
     */
    template <typename T>
    T read(const std::string& key);
    /**
     * Update existing value to a blob.
     * If key does not exist, it is created.
     * The template type T must have valid specialization for 
     * BlobInput class.
     * 
     * @param key The key.
     * @param value The value.
     * @throws std::runtime_error if operation fails.
     */
    template <typename T>
    void update(const std::string& key, const T& value);
    /**
     * Delete the given key.
     *
     * @param key The key.
     * @throws std::runtime_error if operation fails.
     */
    void del(const std::string& key);
    /**
     * Get a list of keys matching the given pattern.
     *
     * @return Vector of keys matched to pattern.
     */
    std::vector<std::string> keys(const std::string& pattern);

private:
    void createImpl(const std::string& key, litestore_blob_t blobIn);
    void readImpl(const std::string& key, void* blobOut);
    void updateImpl(const std::string& key, litestore_blob_t blobIn);

    ErrorFunc m_errorFunc = {};
    detail::Handle m_litestore = nullptr; 
};

/**
 * Template to convert T to litestore_blob for writing to Litestore (input).
 * This can be specialized for custom types
 * and is used so that it can have state
 * e.g. internal buffer to serialize the data to.
 * 
 * The provided templates work for POD types.
 */
template <typename T>
struct BlobInput
{
    static_assert(std::is_trivially_copyable<T>::value, "Type must be POD!");
    const T& value;
    /**
     * Specializations must have these methods.
     */
    BlobInput(const T& v)
        : value(v)
    {}
    litestore_blob_t blob()
    {
        return litestore_make_blob(&value, sizeof(T));
    }
};
template <typename T>
struct BlobOutput
{
    static_assert(std::is_trivially_copyable<T>::value, "Type must be POD!");
    T& value;
    /**
     * Specializations must have these methods.
     */
    BlobOutput(T& v)
        : value(v)
    {}
    void* data()
    {
        return &value;
    }
};
// Specialization for nullptr_t
template <>
struct BlobInput<std::nullptr_t>
{

    BlobInput(const std::nullptr_t&) {};
    litestore_blob_t blob()
    {
        return litestore_make_blob(nullptr, 0);
    }
};
template <>
struct BlobOutput<std::nullptr_t>
{
    BlobOutput(std::nullptr_t&) {};
    void* data()
    {
        return nullptr;
    }
};

template <typename T>
inline
void Litestore::create(const std::string& key, const T& value)
{
    using namespace lscpp;
    BlobInput<T> bi(value);
    createImpl(key, bi.blob());
}

template <typename T>
inline
T Litestore::read(const std::string& key)
{
    using namespace lscpp;
    T value;
    BlobOutput<T> bo(value);
    readImpl(key, bo.data());

    return value;
}

template <typename T>
inline
void Litestore::update(const std::string& key, const T& value)
{
    using namespace lscpp;
    BlobInput<T> bi(value);
    updateImpl(key, bi.blob());
}

} // namespace lscpp