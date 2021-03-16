#include <iostream>
#include <unistd.h>

#include "libraries/xlib.h"

#include "./trac.h"
#include "./registry.h"

#include "./variable.h"
#include "./variables/void.h"
#include "./variables/boolean.h"
#include "./variables/ident.h"
#include "./variables/int.h"

Trac::Trac(std::string triggername, std::vector<Variable *> triggerinput, std::vector<std::string> outputnames, std::vector<Call *> conditions, std::vector<Call *> actions)
{
    Registry *registry = Registry::getInstance();
    TriggerTemplate *triggertemplate = registry->gTrigger(triggername);
    this->trigger = triggertemplate->createTrigger(triggerinput, this);
    this->triggernames = outputnames;

    this->conditions = conditions;
    this->actions = actions;
}

void Trac::onTrigger(std::vector<Variable *> parameters)
{
    for (long unsigned int i = 0; i < parameters.size(); i++)
    {
        Variable *variable = parameters[i];
        std::string name = this->triggernames[i];

        //Delete old and unused variables
        if (this->ctx.has(name))
        {
            delete this->ctx.get(name);
        }
        this->ctx.set(name, variable);
    }
    for (auto condition : this->conditions)
    {
        Variable *result = condition->execute(&this->ctx);
        if (Boolean *boolresult = dynamic_cast<Boolean *>(result))
        {
            if (!boolresult->value)
            {
                delete boolresult;
                return;
            }
        }
        else
        {
            std::cout << "No boolean result from condition " << condition->getName() << std::endl;
            delete result;
            return;
        }
        delete result;
    }
    for (auto action : this->actions)
    {
        Variable *result = action->execute(&this->ctx);
        //Memory Management! yay
        delete result;
    }
}

int main(int argc, char *argv[])
{

    Registry *registry = Registry::getInstance();
    TriggerTemplate *triggertemplate = registry->gTrigger("active_window_change");
    std::vector<std::string> names;
    names.push_back("window");

    std::vector<Call *> actions;
    std::vector<Call *> conditions;

    std::vector<Variable *> params;
    params.push_back(new Ident("window"));
    Call * call = new Call("window_name", params);

    params.clear();
    params.push_back(call);
    actions.push_back(new Call("print", params));

    params.clear();
    params.push_back(new Int(0x6c0000b));
    conditions.push_back(new Call("is_active", params));

    Trac *trac = new Trac("active_window_change", std::vector<Variable *>(), names, conditions, actions);
    //Trigger * trigger = triggertemplate->createTrigger(std::vector<Variable*>(), );

    EventQueue::getInstance()->runLoop();
    return 0;
}