#pragma once

#include <vector>

#include "../variable.h"

class List : public Variable{
    public:
        std::vector<shared_ptr<Variable>> value;

        List(std::vector<shared_ptr<Variable>> value);
        ~List();
        string asString();
};