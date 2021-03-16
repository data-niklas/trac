#pragma once

#include <vector>

#include "./variable.h"


typedef Variable* (*FunctionCallback)(std::vector<Variable*>);

class Function{
    public:
        Function(std::string name, FunctionCallback callback);

        Variable* call(std::vector<Variable*> vars);
        std::string getName();

    private:
        FunctionCallback callback;
        std::string name;
};