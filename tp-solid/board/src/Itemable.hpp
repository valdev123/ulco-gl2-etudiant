#pragma once

#include <vector>
#include <string>

class Itemable {
    public:
        virtual ~Itemable() = default;
        virtual std::vector<std::string> getItems() const = 0;
};

