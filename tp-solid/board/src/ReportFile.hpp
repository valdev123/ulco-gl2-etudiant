#pragma once

#include "fstream"

#include "Reportable.hpp"

class ReportFile : public Reportable{
    public :

    ReportFile(const std::string& fileName) : _ofs(fileName) {}

    void report(const Board & b) override{
        _ofs << b.getTitle() << std::endl;
        for (const std::string & item : b.getItems())
            _ofs << item << std::endl;
        _ofs << std::endl;
    }

    private :

    std::ofstream _ofs;

};