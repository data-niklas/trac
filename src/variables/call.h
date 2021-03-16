#pragma once

#include "../function.h"
#include "../variable.h"

class Call : public Variable {
    public:
        Call(std::string name, std::vector<Variable*> variables);
        std::vector<Variable*> variables;
        Variable* execute(Context* context);
        std::string getName();
        bool isExecutable();

    private:
        Function* function;
};