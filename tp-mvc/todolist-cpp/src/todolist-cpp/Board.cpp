#include <todolist-cpp/Board.hpp>
#include <algorithm>

Board::Board() : _nextId(1){
}

void Board::addTodo(std::string desc){
    Task t{_nextId, desc};
    _todo.push_back(t);
    _nextId++;
}
void Board::toDone(int id_task){
    auto searchId = [id_task](const Task & t){
        return t._id == id_task;
    };
    auto it = std::find_if(_todo.begin(), _todo.end(), searchId);
    if(it != _todo.end()){
        _done.push_back(*it);
        _todo.erase(it);
    }
}