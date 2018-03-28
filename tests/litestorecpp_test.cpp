#include "catch.hpp"

#include "litestorecpp/litestorecpp.hpp"

TEST_CASE("Default constructor works")
{
    litestore::Litestore ls;
    REQUIRE(!ls.is_open());
}