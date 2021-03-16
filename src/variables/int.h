#pragma once

#include "../variable.h"

class Int : public Variable{
    public:
        int value;

        Int(int value);
        std::string asString();
};