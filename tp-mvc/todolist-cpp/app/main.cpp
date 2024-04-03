#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>

int main() {

    Task t {1, "TODO"};
    std::cout << showTask(t) << std::endl;

    Board b;
    std::string desc = "Faire son TP de GL";
    b.addTodo(desc);
    desc = "Faire son 2ème TP de GL";
    b.addTodo(desc);
    printBoard(std::cout,b);

    return 0;
}

