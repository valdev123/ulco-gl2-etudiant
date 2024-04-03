#pragma once

#include "Task.hpp"
#include "Board.hpp"
#include <string>

std::string showTask(const Task & t);

void printBoard(std::ostream & ofs,const Board & b);
