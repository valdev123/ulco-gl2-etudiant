#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>

int main() {

    Task t {1, "TODO"};
    std::cout << showTask(t) << std::endl;

    Board b;
    std::string desc1 = "Faire son TP de GL";
    b.addTodo(desc1);
    std::cout << "Board :" << std::endl;
    std::cout << showTask(b._todo.back()) << std::endl;

    return 0;
}

