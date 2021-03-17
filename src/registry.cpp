#include <iostream>

#include "./registry.h"
#include "./triggers/xlibtriggers.h"

#include "./triggertemplates/simpletriggertemplate.h"
#include "./triggertemplates/timedtriggertemplate.h"

#include "./functions/std/std.h"
#include "./functions/xlibfunctions.h"

#include "./variables/literal.h"

Registry::Registry(){
    this->registerTriggerTemplates();
    this->registerFunctions();
}

void Registry::registerTriggerTemplates(){
    this->rTrigger(new SimpleTriggerTemplate("active_window_change",[](std::vector<Variable*>,Trac* c)->Trigger*{
        return new ActiveWindowChangeTrigger(c);
    }));
    this->rTrigger(new TimedTriggerTemplate());
}


void Registry::registerFunctions(){
    registerStd(this);
    registerXLibFunctions(this);

    this->rFunction(new Function("print",[](std::vector<Variable*> vars)->Variable*{
        for (auto var : vars){
            if (String* v = dynamic_cast<String*>(var)){
                std::cout << v->value << std::endl;
            }
        }
        return new Void();
    }));
};

void Registry::rTrigger(TriggerTemplate*trigger){
    auto name = trigger->getName();
    if (this->triggers.count(name) == 0){
        this->triggers[name] = trigger;
    }
    else{
        std::cout << "Trigger " << name << " already exists" << std::endl;
    }
}
void Registry::rFunction(Function*function){
    auto name = function->getName();
    if (this->functions.count(name) == 0){
        this->functions[name] = function;
    }
    else{
        std::cout << "Function " << name << " already exists" << std::endl;
    }
}

bool Registry::eTrigger(std::string name){
    return this->triggers.count(name) != 0;
}
bool Registry::eFunction(std::string name){
    return this->functions.count(name) != 0;
}
TriggerTemplate* Registry::gTrigger(std::string name){
    return this->triggers[name];
}
Function* Registry::gFunction(std::string name){
    return this->functions[name];
}
void Registry::addTrac(Trac trac){
    this->tracs.push_back(trac);
}

Registry* Registry::getInstance(){
    static Registry* registry = new Registry();
    return registry;
}