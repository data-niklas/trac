#include <iostream>
#include <unistd.h>

#include "libraries/xlib.h"

#include "./trac.h"
#include "./registry.h"

#include "./variable.h"
#include "./variables/literal.h"
#include "./variables/ident.h"
#include "./logger.h"

#include "./parser/TracReader.h"

Trac::Trac(string triggername, vector<shared_ptr<Variable>> triggerinput, vector<string> outputnames, vector<Call *> conditions, vector<Call *> actions)
{
    Registry *registry = Registry::getInstance();
    TriggerTemplate *triggertemplate = registry->gTrigger(triggername);
    this->trigger = triggertemplate->createTrigger(triggerinput, this);
    this->triggernames = outputnames;

    this->conditions = conditions;
    this->actions = actions;
}

void Trac::onTrigger(vector<shared_ptr<Variable>> parameters)
{
    for (long unsigned int i = 0; i < parameters.size(); i++)
    {
        shared_ptr<Variable> variable = parameters[i];
        string name = this->triggernames[i];

        //Delete old and unused variables
        if (this->ctx.has(name))
        {
            //delete this->ctx.get(name);
        }
        this->ctx.set(name, variable);
    }
    for (auto condition : this->conditions)
    {
        shared_ptr<Variable> result = condition->execute(&this->ctx);
        if (shared_ptr<Boolean> boolresult = dynamic_pointer_cast<Boolean>(result))
        {
            if (!boolresult->value)
            {
                return;
            }
        }
        else
        {
            Logger::getLogger()->warning("No boolean result from condition " + condition->getName());
            return;
        }
    }
    for (auto action : this->actions){
        action->execute(&this->ctx);
    }
}

int main(int argc, char *argv[])
{

    parser::TracReader reader;
    TracResult result = reader.parseFromString("active_window_change():window?!println(window_name(window));timed(1000):m?!println(format_time(m\"%H:%M:%S\"));");

    Logger::getLogger()->info("Loaded all Tracs");
    EventQueue::getInstance()->runLoop();
    return 0;
}