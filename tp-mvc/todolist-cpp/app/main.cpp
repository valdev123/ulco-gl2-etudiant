#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hpp>

#include <iostream>
#include <sstream>

int main() {
    Board b;
    std::string input, cmd, rst;
    while(true){
        printBoard(std::cout,b);
        std::getline(std::cin,input);
        std::istringstream iss(input);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);

        if(cmd == "add" and rst != ""){
            b.addTodo(rst);
        }
        else if(cmd == "done" and rst != ""){
            bool is_digit = true;
            for(char i : rst){
                if(!std::isdigit(i)){
                    is_digit = false;
                    break;
                }
            }
            if(is_digit){
                b.toDone(std::stoi(rst));
            }
        }
        else if(cmd == "quit"){
            break;
        }

    }

    return 0;
}

