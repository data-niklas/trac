#pragma once

#include <string>

#include "../variable.h"

class Boolean : public Variable{
    public:
        bool value;

        Boolean(bool value);
        ~Boolean();
        string asString();
};