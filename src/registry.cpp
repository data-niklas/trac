#include "./registry.h"
#include "./triggers/xlibtriggers.h"

#include "./triggertemplates/simpletriggertemplate.h"
#include "./triggertemplates/timedtriggertemplate.h"

#include "./functions/std/std.h"
#include "./functions/xlibfunctions.h"

#include "./variables/literal.h"
#include "./logger.h"

Registry::Registry(){
    this->registerTriggerTemplates();
    this->registerFunctions();
}

void Registry::registerTriggerTemplates(){
    this->rTrigger(new SimpleTriggerTemplate("active_window_change",[](vector<shared_ptr<Variable>>,Trac* c)->Trigger*{
        return new ActiveWindowChangeTrigger(c);
    }));
    this->rTrigger(new TimedTriggerTemplate());
}


void Registry::registerFunctions(){
    registerStd(this);
    registerXLibFunctions(this);
};

void Registry::rTrigger(TriggerTemplate*trigger){
    auto name = trigger->getName();
    if (this->triggers.count(name) == 0){
        this->triggers[name] = trigger;
    }
    else{
        Logger::getLogger()->warning("Trigger " + name + " already exists");
    }
}
void Registry::rFunction(Function*function){
    auto name = function->getName();
    if (this->functions.count(name) == 0){
        this->functions[name] = function;
    }
    else{
        Logger::getLogger()->warning("Function " + name + " already exists");
    }
}

bool Registry::eTrigger(string name){
    return this->triggers.count(name) != 0;
}
bool Registry::eFunction(string name){
    return this->functions.count(name) != 0;
}
TriggerTemplate* Registry::gTrigger(string name){
    return this->triggers[name];
}
Function* Registry::gFunction(string name){
    return this->functions[name];
}
void Registry::addTrac(Trac trac){
    this->tracs.push_back(trac);
}

Registry* Registry::getInstance(){
    static Registry* registry = new Registry();
    return registry;
}