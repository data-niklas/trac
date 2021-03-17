#pragma once

#include "../trigger.h"
#include "../triggertemplate.h"
#include "../triggers/timedtrigger.h"

class TimedTriggerTemplate : public TriggerTemplate{
    public:    
        Trigger * createTrigger(std::vector<Variable*> parameters, Trac* callback){
            if (parameters.size() == 1){
                if (Int* interval = dynamic_cast<Int*>(parameters[0])){
                     return new TimedTrigger(callback, interval->value);
                }
                else return new TimedTrigger(callback, 1000);
            }
            else{
                return new TimedTrigger(callback, 1000);
            }
        }
        std::string getName(){
            return "timed";
        }
};