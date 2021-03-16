#pragma once

#include <string>

#include "../variable.h"

class String : public Variable{
    public:
        std::string value;

        String(std::string value);
        std::string asString();
};