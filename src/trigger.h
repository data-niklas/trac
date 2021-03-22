#pragma once


#include <vector>
#include <string>

#include "./variable.h"

typedef void (*VariableCallback)(vector<shared_ptr<Variable>>);

class Trigger{
    public:
        Trigger(){}
        //Called on each iteration / tick / interval
        virtual void onCheck(long time, long millidiff){}
        virtual void stop(){}
};