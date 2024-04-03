#include <todolist-cpp/Board.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test board 1" ) {
    Board b;
    REQUIRE( b.getNextId() == 1 );
    REQUIRE( b._todo.empty() == true );
    REQUIRE( b._done.empty() == true );
}

TEST_CASE( "test addTodo" ) {
    Board b;
    std::string desc = "faire son TP de GL";
    b.addTodo(desc);
    REQUIRE( b.getNextId() == 2 );
    REQUIRE( b._todo.empty() == false );
    REQUIRE( b._todo.back()._id == 1);
    REQUIRE( b._todo.back()._name == desc);
}
