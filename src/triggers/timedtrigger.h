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
            vector<shared_ptr<Variable>> params;
            params.push_back(shared_ptr<Variable>(new Int(time)));
            this->trigger(params);
        }
};