#pragma once

namespace litestore
{

class Litestore
{
public:
    Litestore() = default;
    bool is_open() const
    {
        return false;
    }
};

} // namespace litestore