#include <todolist-cpp/View.hpp>
#include <iostream>

std::string showTask(const Task &t){
    return std::to_string(t._id) + ". " + t._name;
}

void printBoard(std::ostream & ofs, const Board &b){
    ofs << "Board :\n";
    
    if(!b._todo.empty()){
        ofs << "\tTodo :\n";
        for(auto i : b._todo){
            ofs << "\t\t" << showTask(i) << "\n";
        } 
    }
    if(!b._done.empty()){
        ofs << "\tDone :\n";
        for(auto i : b._done){
            ofs << "\t\t" << showTask(i) << "\n";
        } 
    }
}