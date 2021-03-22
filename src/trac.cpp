#include <iostream>
#include <unistd.h>
#include <chrono>

#include "libraries/xlib.h"

#include "./trac.h"
#include "./registry.h"

#include "./variable.h"
#include "./variables/literal.h"
#include "./variables/ident.h"
#include "./logger.h"
#include "./error.h"

#include "./parser/TracReader.h"

Trac::Trac(string triggername, vector<shared_ptr<Variable>> triggerinput, vector<string> outputnames, vector<Call *> conditions, vector<Call *> actions)
{
    Registry *registry = Registry::getInstance();

    //Checking errors
    if (!registry->eTrigger(triggername))
    {
        throw NotFound("Trigger " + triggername, "the registry");
    }
    for (auto &var : triggerinput)
    {
        if (shared_ptr<Call> callvar = dynamic_pointer_cast<Call>(var))
        {
            if (callvar->getName().empty())
            {
                throw TracError("Trac");
            }
        }
    }
    for (Call *var : conditions)
    {
        if (var->getName().empty())
        {
            throw TracError("Trac");
        }
    }
    for (Call *var : actions)
    {
        if (var->getName().empty())
        {
            throw TracError("Trac");
        }
    }

    TriggerTemplate *triggertemplate = registry->gTrigger(triggername);
    this->trigger = triggertemplate->createTrigger(triggerinput, this);
    this->triggernames = outputnames;

    this->conditions = conditions;
    this->actions = actions;
}

void Trac::onTrigger(vector<shared_ptr<Variable>> parameters)
{
    Logger::getLogger()->debug("Triggered Trac");
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

    try
    {
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
        for (auto action : this->actions)
        {
            action->execute(&this->ctx);
        }
    }
    catch (InvalidArguments &e)
    {
        e.print();
    }
    catch (InvalidType  &e)
    {
        e.print();
    }
    catch (NotFound  &e)
    {
        e.print();
    }
}

int main(int argc, char *argv[])
{
    Logger *logger = Logger::getLogger();
    logger->loglevel = LogLevel::Info;
    parser::TracReader reader;
    auto start = chrono::system_clock::now();
    TracResult result = reader.parseFromString("active_window_change():window?!println(window_name(window));//timed(1000):m?!println(format_time(m\"%H:%M:%S\"));");
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start);
    logger->debug("Loaded " + to_string(result.value.size()) + " Trac(s) in " + to_string(duration.count()) + " milliseconds");

    Logger::getLogger()->info("Loaded all Tracs");
    EventQueue::getInstance()->runLoop();
    return 0;
}