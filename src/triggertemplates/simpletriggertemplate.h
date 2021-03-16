#pragma once

#include "../trigger.h"
#include "../triggertemplate.h"

typedef Trigger*(*CreateTriggerCallback)(std::vector<Variable*>, Trac*);

class SimpleTriggerTemplate : public TriggerTemplate{
    public:
        SimpleTriggerTemplate(std::string name, CreateTriggerCallback callback){
            this->name = name;
            this->callback = callback;
        }

        Trigger * createTrigger(std::vector<Variable*> parameters, Trac* callback){
            return this->callback(parameters, callback);
        }
        std::string getName(){
            return this->name;
        }
    private:
        std::string name;
        CreateTriggerCallback callback;
};