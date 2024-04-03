#include <todolist-cpp/View.hpp>
#include <catch2/catch.hpp>
#include <ostream>
#include <sstream>

TEST_CASE( "test showTask 1" ) {
    Task t {1, "TODO"};
    std::string res = showTask(t);
    REQUIRE( res == "1. TODO" );
}

TEST_CASE( "test printBoard empty" ) {
    Board b;
    std::ostringstream oss;
    printBoard(oss,b);
    auto expected = "Board :\n";
    REQUIRE( oss.str() == expected );
}

TEST_CASE( "test printBoard 1 elm" ) {
    Board b;
    std::string desc = "test 1";
    b.addTodo(desc);
    std::ostringstream oss;
    printBoard(oss,b);
    auto expected = "Board :\n\tTodo :\n\t\t1. test 1\n";
    REQUIRE( oss.str() == expected );
}

TEST_CASE( "test printBoard 2 elm" ) {
    Board b;
    std::string desc = "test 1";
    b.addTodo(desc);
    desc = "test 2";
    b.addTodo(desc);
    b.toDone(1);
    std::ostringstream oss;
    printBoard(oss,b);
    auto expected = "Board :\n\tTodo :\n\t\t2. test 2\n\tDone :\n\t\t1. test 1\n";
    REQUIRE( oss.str() == expected );
}
