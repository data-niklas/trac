#pragma once

#include <vector>
#include <string>

#include "./variable.h"
#include "./trigger.h"
#include "./triggers/simpletrigger.h"

class TriggerTemplate{
    public:
        virtual string getName(){
            return "triggertemplate";
        }
        virtual Trigger * createTrigger(vector<shared_ptr<Variable>> parameters, Trac* callback){
            return new Trigger();
        }
};