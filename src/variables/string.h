#pragma once

#include <string>

#include "../variable.h"

class String : public Variable{
    public:
        string value;

        String(string value);
        ~String();
        string asString();
};