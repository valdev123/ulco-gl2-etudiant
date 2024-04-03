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
    REQUIRE( b._todo.size() == 1 );
    REQUIRE( b._todo.back()._id == 1);
    REQUIRE( b._todo.back()._name == desc);

    desc = "Faire ton 2ème TP de GL";
    b.addTodo(desc);
    REQUIRE( b.getNextId() == 3 );
    REQUIRE( b._todo.empty() == false );
    REQUIRE( b._todo.size() == 2 );
    REQUIRE( b._todo.back()._id == 2);
    REQUIRE( b._todo.back()._name == desc);
}

TEST_CASE( "test toDone empty" ) {
    Board b;
    b.toDone(5);
    REQUIRE( b._done.empty() == true );
}

TEST_CASE( "test toDone 1 elm" ) {
    Board b;
    b.addTodo("test 1");
    int size = b._todo.size();
    b.toDone(1);
    REQUIRE( size == 1 );
    REQUIRE( b._done.size() == 1 );
    REQUIRE( b._done.back()._id == 1 );
    REQUIRE( b._done.back()._name == "test 1" );
    REQUIRE( b._todo.size() == size-1);
}

TEST_CASE( "test toDone 2 elm" ) {
    Board b;
    b.addTodo("test 1");
    b.addTodo("test 2");
    int size = b._todo.size();
    
    b.toDone(1);
    REQUIRE( size == 2 );
    REQUIRE( b._done.size() == 1 );
    REQUIRE( b._done.back()._id == 1 );
    REQUIRE( b._done.back()._name == "test 1" );
    REQUIRE( b._todo.size() == size-1);

    b.toDone(2);
    REQUIRE( b._done.size() == 2 );
    REQUIRE( b._done.back()._id == 2 );
    REQUIRE( b._done.back()._name == "test 2" );
    REQUIRE( b._todo.size() == size-2);
}
