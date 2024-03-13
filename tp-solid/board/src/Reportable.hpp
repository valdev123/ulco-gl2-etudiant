#pragma once

#include "Board.hpp"

class Reportable {
    public:
        virtual ~Reportable() = default;
        virtual void report(const Board & b) = 0;
};