#pragma once
#include "./simpletrigger.h"
#include "../eventqueue.h"
#include "../variables/int.h"

class TimedTrigger : public SimpleTrigger{
    public:
        TimedTrigger(Trac* callback, long millisinterval) : SimpleTrigger(callback){
            EventQueue::getInstance()->registerInterval(this, millisinterval);
        }
        void onCheck(long time, long millidiff){
            std::vector<Variable*> params;
            params.push_back(new Int(time));
            this->trigger(params);
        }
};