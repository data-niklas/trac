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
        bool eTrigger(std::string name);
        bool eFunction(std::string name);
        TriggerTemplate* gTrigger(std::string name);
        Function* gFunction(std::string name);
        std::map<std::string, Function*> functions;
        std::map<std::string, TriggerTemplate*> triggers;
        std::vector<Trac> tracs;

        static Registry* getInstance();
};