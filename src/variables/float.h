#pragma once

#include "../variable.h"

class Float : public Variable{
    public:
        double value;

        Float(double value);
        ~Float();
        string asString();
};