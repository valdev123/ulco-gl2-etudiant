#pragma once

#include "Board.hpp"
#include "string"

class NumBoard : public Board {
    public :

    NumBoard() : _cpt(0) {}

    void addNum(const std::string & t) {
        _cpt++;
        add(std::to_string(_cpt) + ": " + t);
    }

    private :
    int _cpt;

};