/**
 * Copyright (c) 2018 Markku Linnoskivi
 *
 * See the file LICENSE for copying permission.
 */
#include "litestorecpp/litestorecpp.hpp"

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

    if (!blobIn.data)
    {
        throwOnError(
            litestore_create_null(m_litestore.get(), slice(key))
        );
    }
    else
    {
        throwOnError(
            litestore_create(m_litestore.get(), slice(key), blobIn)
        );
    }
}

void Litestore::readImpl(const std::string& key, void* blobOut)
{
    throwIfClosed(*this);
 
    if (!blobOut)
    {
        throwOnError(
            litestore_read_null(m_litestore.get(), slice(key))
        );
    }
    else
    {
        throwOnError(
            litestore_read(m_litestore.get(), slice(key), &read_cb, blobOut)
        );
    }
}

void Litestore::updateImpl(const std::string& key, litestore_blob_t blobIn)
{
    throwIfClosed(*this);

    if (!blobIn.data)
    {
        throwOnError(
            litestore_update_null(m_litestore.get(), slice(key))
        );
    }
    else
    {
        throwOnError(
            litestore_update(m_litestore.get(), slice(key), blobIn)
        );
    }
}


namespace detail
{

void LSDelete::operator()(litestore* handle) const
{
    litestore_close(handle);
}

}  // namespace detail
}  // namespace lscpp