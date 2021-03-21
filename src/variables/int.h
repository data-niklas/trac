#pragma once

#include "../variable.h"

class Int : public Variable{
    public:
        long value;

        Int(long value);
        ~Int();
        string asString();
};