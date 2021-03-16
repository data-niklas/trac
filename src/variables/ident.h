#pragma once

#include <string>

#include "../variable.h"
#include "../context.h"

class Ident : public Variable{
    public:
        std::string value;

        Ident(std::string value);
        std::string asString();
        Variable* execute(Context* context);
        bool isExecutable();
};