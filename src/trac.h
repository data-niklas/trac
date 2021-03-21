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
        Trac(string triggername, vector<shared_ptr<Variable>> triggerinput, vector<string> outputnames, vector<Call*> conditions, vector<Call*> actions);
        void onTrigger(vector<shared_ptr<Variable>> parameters);
        Context ctx;

    private:
        Trigger*trigger;
        vector<Call*> conditions;
        vector<Call*> actions;
        vector<string> triggernames;
};