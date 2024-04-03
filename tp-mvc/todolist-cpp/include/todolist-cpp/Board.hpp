#pragma once

#include <todolist-cpp/Task.hpp>
#include <vector>

class Board {

    private:
        int _nextId;

    public:
        std::vector<Task> _todo;
        std::vector<Task> _done;

        Board();
        int getNextId(){ return _nextId; }
        void addTodo(std::string);
};
