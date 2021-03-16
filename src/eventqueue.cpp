#include "./eventqueue.h"

Event::Event(Trac* callback, std::vector<Variable *> variables)
{
    this->callback = callback;
    this->variables = variables;
}

void EventQueue::addEvent(Event event)
{
    this->mutex.lock();
    this->events.push_back(event);
    this->mutex.unlock();
}

void EventQueue::registerTick(Trigger *trigger)
{
    this->registerInterval(trigger, 1);
}

void EventQueue::registerInterval(Trigger *trigger, long interval)
{
    this->intervals[interval].push_back(trigger);
}

long currentMillis(){
    timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void EventQueue::runLoop()
{
    this->running = true;
    long last_time = currentMillis();
    long time_start;
    while (this->running)
    {
        time_start = currentMillis();
        long milli_diff = time_start - last_time;

        //Sleep at least 30 millis
        if (milli_diff < 30){
            std::this_thread::sleep_for(std::chrono::milliseconds(30-milli_diff));
            milli_diff = 30;
        }

        last_time = time_start;
        
        //Run all triggers
        for(auto &kv : this->intervals){
            if (time_start % kv.first == 0){//Check interval
                for (auto trigger : kv.second){
                    trigger->onCheck(time_start, milli_diff);
                }
            }
        }

        //Process all events
        for (auto &event : this->events){
            event.callback->onTrigger(event.variables);
        }
        this->events.clear();
    }
}

EventQueue *EventQueue::getInstance()
{
    static EventQueue *instance = new EventQueue();
    return instance;
}