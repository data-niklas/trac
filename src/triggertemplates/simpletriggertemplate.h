#pragma once

#include "../trigger.h"
#include "../triggertemplate.h"

typedef Trigger*(*CreateTriggerCallback)(vector<shared_ptr<Variable>>, Trac*);

class SimpleTriggerTemplate : public TriggerTemplate{
    public:
        SimpleTriggerTemplate(string name, CreateTriggerCallback callback){
            this->name = name;
            this->callback = callback;
        }

        Trigger * createTrigger(vector<shared_ptr<Variable>> parameters, Trac* callback){
            return this->callback(parameters, callback);
        }
        string getName(){
            return this->name;
        }
    private:
        string name;
        CreateTriggerCallback callback;
};