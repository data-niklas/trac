#pragma once

#include "../trigger.h"
#include "../eventqueue.h"

class SimpleTrigger : public Trigger{
    public:
        SimpleTrigger(Trac* callback){
            this->callback = callback;
        }
        void trigger(std::vector<Variable*> variables){
            EventQueue::getInstance()->addEvent(Event(this->callback, variables));
        }

    private:
        Trac* callback;
};