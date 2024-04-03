#include <todolist-cpp/View.hpp>
#include <iostream>

std::string showTask(const Task &t){
    return std::to_string(t._id) + ". " + t._name;
}