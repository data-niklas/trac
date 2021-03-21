#pragma once

#include "../function.h"
#include "../variable.h"

class Call : public Variable {
    public:
        Call(string name, vector<shared_ptr<Variable>> variables);
        vector<shared_ptr<Variable>> variables;
        shared_ptr<Variable> execute(Context* context);
        string getName();
        bool isExecutable();

    private:
        Function* function;
};