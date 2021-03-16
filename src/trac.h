#pragma once
#include <vector>
#include <map>
#include <string>

#include "./trigger.h"
#include "./variable.h"
#include "./context.h"
#include "./variables/call.h"

class Trac{
    public:
        Trac(std::string triggername, std::vector<Variable*> triggerinput, std::vector<std::string> outputnames, std::vector<Call*> conditions, std::vector<Call*> actions);
        void onTrigger(std::vector<Variable*> parameters);
        Context ctx;

    private:
        Trigger*trigger;
        std::vector<Call*> conditions;
        std::vector<Call*> actions;
        std::vector<std::string> triggernames;
};