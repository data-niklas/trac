#pragma once

#include <vector>

#include "./variable.h"


typedef shared_ptr<Variable> (*FunctionCallback)(vector<shared_ptr<Variable>>);

class Function{
    public:
        Function(string name, FunctionCallback callback);

        shared_ptr<Variable> call(vector<shared_ptr<Variable>> vars);
        string getName();

    private:
        FunctionCallback callback;
        string name;
};