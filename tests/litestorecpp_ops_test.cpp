#include <type_traits>

#include "catch.hpp"

#include "litestorecpp/litestorecpp.hpp"

using namespace lscpp;

TEST_CASE("Operations throw if not opened")
{
    Litestore ls;
    REQUIRE_FALSE(ls.is_open());

    SECTION("create null")
    {
        CHECK_THROWS_AS(ls.create("key"), std::runtime_error);
    }
    SECTION("create blob")
    {
        CHECK_THROWS_AS(ls.create("key", 42), std::runtime_error);
    }
    SECTION("read null")
    {
        CHECK_THROWS_AS(ls.read("key"), std::runtime_error);
    }
    SECTION("read blob")
    {
        CHECK_THROWS_AS(ls.read<int>("key"), std::runtime_error);
    }
    SECTION("update null")
    {
        CHECK_THROWS_AS(ls.update("key"), std::runtime_error);
    }
    SECTION("update blob")
    {
        CHECK_THROWS_AS(ls.update("key", 10), std::runtime_error);
    }
}

TEST_CASE("CRUD on null type")
{
    Litestore ls{":memory:"};
    REQUIRE(ls.is_open());

    SECTION("Read throws if not found")
    {
        const bool rv = ls.read("null"); 
        CHECK_FALSE(rv);
    }

    SECTION("create and then read")
    {
        ls.create("null");
        const bool rv = ls.read("null");
    
        CHECK(rv);
    }

    SECTION("Update null on empty")
    {
        ls.update("null");
        const bool rv1 = ls.read("null");
        CHECK(rv1);
        
        ls.update("null");
        const bool rv2 = ls.read("null");
        CHECK(rv2);
    }
}

TEST_CASE("CRUD on blob type")
{
    Litestore ls{":memory:"};
    REQUIRE(ls.is_open());

    SECTION("Read throws if not found")
    {
        CHECK_THROWS_AS(ls.read<int>("key"), std::runtime_error);
    }

    SECTION("create and then read int")
    {
        ls.create("key", 42);
        const int i = ls.read<int>("key");

        CHECK(i == 42);
    }
    
    SECTION("create and then read custom trivailly copyable struct")
    {
        // @note This struct is trivailly copyable but not POD
        // cause it has a constructor.
        struct S
        {
            S() = default;
            S(int i) : i(i)
            {}
            int i;
        };
        
        S s{42};
        ls.create("key", s);
        const S sOut = ls.read<S>("key");

        CHECK(sOut.i == 42);
    }

    SECTION("Update creates value")
    {
        ls.update("key", 42);
        
        const int i = ls.read<int>("key");

        CHECK(i == 42);
    }
}

TEST_CASE("Delete")
{
    SECTION("Throws if no handle")
    {
        Litestore ls;
        CHECK_THROWS_AS(ls.del("key"), std::runtime_error);
    }

    SECTION("Delete the data")
    {
        Litestore ls(":memory:");
        ls.create("key", 42);

        ls.del("key");
 
        CHECK_THROWS_AS(ls.read<int>("key"), std::runtime_error);
    }
}