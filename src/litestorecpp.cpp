/**
 * Copyright (c) 2018 Markku Linnoskivi
 *
 * See the file LICENSE for copying permission.
 */
#include "litestorecpp/litestorecpp.hpp"

#include <cassert>
#include <cstring>
#include <stdexcept>

#define UNUSED(x) (void)(x)

namespace lscpp
{
namespace
{
void error_trampoline(const int error,
                      const char* desc,
                      void* user_data)
{
    auto func = reinterpret_cast<Litestore::ErrorFunc*>(user_data);
    if (*func)
    {
        (*func)(error, desc);
    }
}

int read_cb(litestore_blob_t value, void* user_data)
{
    std::memcpy(user_data, value.data, value.size);
    return LITESTORE_OK;
}

inline
void throwOnError(const int rc)
{
    if (rc != LITESTORE_OK)
    {
        throw std::runtime_error("Litestore error: " + std::to_string(rc));
    }
}

inline
void throwIfClosed(const Litestore& ls)
{
    if (!ls.is_open())
    {
        throw std::runtime_error("Litestore not opened!");
    }
}

inline
litestore_slice_t slice(const std::string& str)
{
    return litestore_slice(str.c_str(), 0, str.length());
}

detail::Handle createHandle(const char* filename, const litestore_opts& opts)
{
    litestore* ptr = nullptr;
    const auto rc = litestore_open(filename, opts, &ptr);
    if (rc != LITESTORE_OK)
    {
        throw std::runtime_error("Failed to open litestore!");
    }
    
    return detail::Handle(ptr);
}

}  // namespace

Transaction::Transaction(litestore* ls)
    : m_litestore(ls)
{
    assert(ls);

    throwOnError(
        litestore_begin_tx(m_litestore)
    );
    m_state = State::OPEN;
}

Transaction::~Transaction() noexcept
{
    if (m_litestore)
    {
        if (m_state == State::OPEN)
        {
            litestore_rollback_tx(m_litestore);
        }
    }
}

Transaction::Transaction(Transaction&& rhs) noexcept
    : m_litestore(std::exchange(rhs.m_litestore, nullptr)),
      m_state(std::exchange(rhs.m_state, State::INITIAL))
{}

void Transaction::commit()
{
    if (m_litestore)
    {
        if (m_state == State::OPEN)
        {
            throwOnError(
                litestore_commit_tx(m_litestore)
            );
            m_state = State::DONE;
        }
    }
    else
    {
        std::runtime_error("No transaction, commit() called!");
    }
}

void Transaction::rollback()
{
    if (m_litestore)
    {
        if (m_state == State::OPEN)
        {
            throwOnError(
                litestore_rollback_tx(m_litestore)
            );
            m_state = State::DONE;
        }
    }
    else
    {
        std::runtime_error("No transaction, commit() called!");
    }
}


Litestore::Litestore(const char* filename)
    : m_litestore(createHandle(filename, { &error_trampoline, &m_errorFunc }))
{}

bool Litestore::is_open() const noexcept
{
    return (m_litestore != nullptr);
}

void Litestore::close() noexcept
{
    m_litestore.reset();
}

Transaction Litestore::createTx()
{
    return Transaction(m_litestore.get());
}

/** CRUD API */
void Litestore::del(const std::string& key)
{
    throwIfClosed(*this);

    throwOnError(
        litestore_delete(m_litestore.get(), slice(key))
    );
}

void Litestore::createImpl(const std::string& key, litestore_blob_t blobIn)
{
    throwIfClosed(*this);

    throwOnError(
        !blobIn.data ?
            litestore_create_null(m_litestore.get(), slice(key))
            : litestore_create(m_litestore.get(), slice(key), blobIn)
    );
}

void Litestore::readImpl(const std::string& key, void* blobOut)
{
    throwIfClosed(*this);
 
    throwOnError(
        !blobOut ?
            litestore_read_null(m_litestore.get(), slice(key))
            : litestore_read(m_litestore.get(),
                             slice(key),
                             &read_cb,
                             blobOut)
    );
}

void Litestore::updateImpl(const std::string& key, litestore_blob_t blobIn)
{
    throwIfClosed(*this);

    throwOnError(
        !blobIn.data ?
            litestore_update_null(m_litestore.get(), slice(key))
            : litestore_update(m_litestore.get(), slice(key), blobIn)
    );
}


namespace detail
{

void LSDelete::operator()(litestore* handle) const
{
    litestore_close(handle);
}

}  // namespace detail
}  // namespace lscpp