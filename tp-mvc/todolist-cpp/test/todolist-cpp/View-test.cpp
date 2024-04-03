#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test view 1" ) {
    Task t {1, "TODO"};
    std::string res = showTask(t);
    REQUIRE( res == "1. TODO" );
}
