#include <todolist-cpp/Board.hpp>

Board::Board() : _nextId(1){
}

void Board::addTodo(std::string desc){
    Task t{_nextId, desc};
    _todo.push_back(t);
    _nextId++;
}