#pragma once


#include <vector>
#include <string>

#include "./variable.h"
//class Trac;

typedef void (*VariableCallback)(vector<shared_ptr<Variable>>);

class Trigger{
    public:
        Trigger(){}
        //Called on each iteration / tick / interval
        virtual void onCheck(long time, long millidiff){}
        virtual void stop(){}

        //static string getName();
        //static Trigger* createTrigger(vector<shared_ptr<Variable>> parameters, Trac* callback);
};


//typedef Trigger* TriggerCreation(vector<shared_ptr<Variable>> parameters, Trac* callback)