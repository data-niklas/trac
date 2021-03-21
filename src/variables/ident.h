#pragma once

#include <string>

#include "../variable.h"
#include "../context.h"

class Ident : public Variable{
    public:
        string value;

        Ident(string value);
        string asString();
        shared_ptr<Variable> execute(Context* context);
        bool isExecutable();
};