#pragma once

#include "iostream"

#include "Reportable.hpp"

class ReportStdout : public Reportable{
    public :

    void report(const Board & b) override{
        std::cout << b.getTitle() << std::endl;
        for (const std::string & item : b.getItems())
            std::cout << item << std::endl;
        std::cout << std::endl;
    }

    private :

};