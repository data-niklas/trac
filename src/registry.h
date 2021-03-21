#pragma once

#include <map>
#include <vector>
#include <string>

#include "./trigger.h"
#include "./triggertemplate.h"
#include "./function.h"
#include "./trac.h"

class Registry{
    public:
        Registry();
        void addTrac(Trac trac);
        void registerTriggerTemplates();
        void registerFunctions();
        void rTrigger(TriggerTemplate*trigger);
        void rFunction(Function*function);
        bool eTrigger(string name);
        bool eFunction(string name);
        TriggerTemplate* gTrigger(string name);
        Function* gFunction(string name);
        map<string, Function*> functions;
        map<string, TriggerTemplate*> triggers;
        vector<Trac> tracs;

        static Registry* getInstance();
};