#pragma once

#include "iostream"
#include "Board.hpp"

class ReportStdout {
    public :

    void reportStdout(const Board & b) const {
        for (const std::string & item : b.getItems())
            std::cout << item << std::endl;
        std::cout << std::endl;
    }

    private :

};