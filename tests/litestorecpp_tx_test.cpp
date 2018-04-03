#include <type_traits>

#include "catch.hpp"

#include "litestorecpp/litestorecpp.hpp"

using namespace lscpp;

TEST_CASE("Transaction traits")
{
    CHECK_FALSE(std::is_copy_constructible<Transaction>::value);
    CHECK_FALSE(std::is_copy_assignable<Transaction>::value);
    CHECK_FALSE(std::is_move_assignable<Transaction>::value);

    CHECK(std::is_nothrow_move_constructible<Transaction>::value);
}

TEST_CASE("Transactions")
{
    Litestore ls(":memory:");

    SECTION("Basic construction")
    {
        auto tx = ls.createTx();
        CHECK(tx.state() == Transaction::State::OPEN);
    }
    SECTION("Commit changes state")
    {
        auto tx = ls.createTx();
        tx.commit();
        CHECK(tx.state() == Transaction::State::DONE);
    }
    SECTION("Rollback changes state")
    {
        auto tx = ls.createTx();
        tx.rollback();
        CHECK(tx.state() == Transaction::State::DONE);
    }
    SECTION("Rollback actually rolls back changes")
    {
        {
            auto tx = ls.createTx();
            ls.create("val", 42);
        }
        CHECK_THROWS(ls.read<int>("val"));
    }
    SECTION("Commit stores changes")
    {
        {
            auto tx = ls.createTx();
            ls.create("val", 42);
            tx.commit();
        }
        CHECK(ls.read<int>("val") == 42);

        {
            auto tx = ls.createTx();
            ls.update("val", 50);
            tx.commit();
        }
        CHECK(ls.read<int>("val") == 50);
    }
}