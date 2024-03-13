#pragma once

#include "fstream"
#include "Board.hpp"

class ReportFile {
    public :

    ReportFile(const std::string& fileName) : _ofs(fileName) {}

    void reportFile(const Board & b) {
        for (const std::string & item : b.getItems())
            _ofs << item << std::endl;
        _ofs << std::endl;
    }

    private :

    std::ofstream _ofs;

};