#include <type_traits>

#include "catch.hpp"

#include "litestorecpp/litestorecpp.hpp"

using namespace lscpp;

TEST_CASE("Default constructor works")
{
    Litestore ls;
    REQUIRE_FALSE(ls.is_open());
}

TEST_CASE("Constructor with path opens connection")
{
    Litestore ls(":memory:");
    REQUIRE(ls.is_open());
}

TEST_CASE("Constructor throws if can't open handle")
{
    // root should not be writable
    bool exception = false;
    try
    {
        Litestore ls("/");
    }
    catch (const std::runtime_error&)
    {
        exception = true;
    }
    
    CHECK(exception);
}

TEST_CASE("Litestore is not copyable")
{
    REQUIRE_FALSE(std::is_copy_constructible<Litestore>::value);
    REQUIRE_FALSE(std::is_copy_assignable<Litestore>::value);
}

TEST_CASE("Litestore is movable")
{
    // @note On GCC < 7 std::function move consturctor is not noexcept
    REQUIRE(std::is_move_constructible<Litestore>::value);
    REQUIRE(std::is_move_assignable<Litestore>::value);

    Litestore src(":memory:");
    Litestore trg = std::move(src);
    
    REQUIRE_FALSE(src.is_open());
    REQUIRE(trg.is_open());
}