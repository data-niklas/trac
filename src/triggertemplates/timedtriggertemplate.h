#pragma once

#include "../trigger.h"
#include "../triggertemplate.h"
#include "../triggers/timedtrigger.h"

class TimedTriggerTemplate : public TriggerTemplate{
    public:    
        Trigger * createTrigger(vector<shared_ptr<Variable>> parameters, Trac* callback){
            if (parameters.size() == 1){
                if (shared_ptr<Int> interval = dynamic_pointer_cast<Int>(parameters[0])){
                     return new TimedTrigger(callback, interval->value);
                }
                else return new TimedTrigger(callback, 1000);
            }
            else{
                return new TimedTrigger(callback, 1000);
            }
        }
        string getName(){
            return "timed";
        }
};