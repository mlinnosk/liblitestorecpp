#include <cstddef>
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
        CHECK_THROWS_AS(ls.create("key", nullptr), std::runtime_error);
    }
    SECTION("create blob")
    {
        CHECK_THROWS_AS(ls.create("key", 42), std::runtime_error);
    }
    SECTION("read null")
    {
        CHECK_THROWS_AS(ls.read<std::nullptr_t>("key"), std::runtime_error);
    }
    SECTION("read blob")
    {
        CHECK_THROWS_AS(ls.read<int>("key"), std::runtime_error);
    }
    SECTION("update null")
    {
        CHECK_THROWS_AS(ls.update("key", nullptr), std::runtime_error);
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
        CHECK_THROWS_AS(ls.read<std::nullptr_t>("null"), std::runtime_error);
    }

    SECTION("create and then read")
    {
        ls.create("null", nullptr);
   
        const auto rv = ls.read<std::nullptr_t>("null");
    
        CHECK(rv == nullptr);
    }

    SECTION("Update null on empty")
    {
        ls.update("null", nullptr);
        const auto rv1 = ls.read<std::nullptr_t>("null");
        CHECK(rv1 == nullptr);
        
        ls.update("null", nullptr);
        const auto rv2 = ls.read<std::nullptr_t>("null");
        CHECK(rv2 == nullptr);
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

    SECTION("Non existing does not throw")
    {
        Litestore ls(":memory:");
        CHECK_NOTHROW(ls.del("key"));
    }

    SECTION("Delete the data")
    {
        Litestore ls(":memory:");
        ls.create("key", 42);

        ls.del("key");
 
        CHECK_THROWS_AS(ls.read<int>("key"), std::runtime_error);
    }
}

TEST_CASE("Error function is called")
{
    bool called = false;
    Litestore ls{":memory:", [&](const int, const char*) { called = true; }};

    ls.create("key", nullptr);
    // creating a duplicate fails and calls the error func
    CHECK_THROWS_AS(ls.create("key", nullptr), std::runtime_error);
    
    CHECK(called);
}

TEST_CASE("Reading keys")
{
    Litestore ls(":memory:");
    
    SECTION("No match produces empty list")
    {
        const auto keys = ls.keys("*");
     
        REQUIRE(keys.empty());    
    }

    SECTION("Get all returns every key")
    {
        auto tx = ls.createTx();
        ls.create("key1", nullptr);
        ls.create("key2", nullptr);
        ls.create("key3", nullptr);

        const auto keys = ls.keys("*");
        tx.rollback();

        REQUIRE(keys.size() == 3);
        CHECK(keys[0] == "key1");
        CHECK(keys[1] == "key2");
        CHECK(keys[2] == "key3");
    }

    SECTION("Get with more specific pattern")
    {
        auto tx = ls.createTx();
        ls.create("key1", nullptr);
        ls.create("key2", nullptr);
        ls.create("key3", nullptr);
        ls.create("foo", nullptr);

        const auto keys = ls.keys("key*");
        tx.rollback();

        REQUIRE(keys.size() == 3);
        CHECK(keys[0] == "key1");
        CHECK(keys[1] == "key2");
        CHECK(keys[2] == "key3");
    }
}