#pragma once

#include <vector>
#include <string>

#include "./variable.h"
#include "./trigger.h"
#include "./triggers/simpletrigger.h"

class TriggerTemplate{
    public:
        virtual std::string getName(){
            return "triggertemplate";
        }
        virtual Trigger * createTrigger(std::vector<Variable*> parameters, Trac* callback){
            return new Trigger();
        }
};