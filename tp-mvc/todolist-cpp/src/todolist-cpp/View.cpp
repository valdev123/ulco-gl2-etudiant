#include <todolist-cpp/View.hpp>
#include <iostream>

std::string showTask(const Task &t){
    return std::to_string(t._id) + ". " + t._name;
}

void printBoard(std::ostream & ofs, const Board &b){
    ofs << "Board :\n";
    for(auto i : b._todo){
        ofs << showTask(i) << "\n";
    }
}