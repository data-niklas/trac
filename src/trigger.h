#pragma once


#include <vector>
#include <string>

#include "./variable.h"

typedef void (*VariableCallback)(std::vector<Variable*>);

class Trigger{
    public:
        Trigger(){}
        //Called on each iteration / tick / interval
        virtual void onCheck(long time, long millidiff){}
};