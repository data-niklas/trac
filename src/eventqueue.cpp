#include "./eventqueue.h"
#include "./logger.h"

Event::Event(Trac *callback, vector<shared_ptr<Variable>> variables)
{
    this->callback = callback;
    this->variables = variables;
}

IntervalBatch::IntervalBatch()
{
    this->last_called = 0;
}

void EventQueue::addEvent(Event event)
{
    this->queue_lock.lock();
    this->events.push_back(event);
    this->queue_lock.unlock();
}

void EventQueue::registerTick(Trigger *trigger)
{
    this->registerInterval(trigger, 1);
}

void EventQueue::registerInterval(Trigger *trigger, long interval)
{
    this->intervals[interval].triggers.push_back(trigger);
}

long currentMillis()
{
    timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void EventQueue::runLoop(long interval)
{
    this->interval = interval;
    this->running = true;
    long last_time = currentMillis();
    long time_start;
    while (this->running)
    {
        time_start = currentMillis();
        long milli_diff = time_start - last_time;
        //Logger::getLogger()->debug("Processed eventqueue in " + to_string(milli_diff) + " milliseconds");

        //Sleep at least 30 millis
        if (milli_diff < this->interval)
        {
            this_thread::sleep_for(chrono::milliseconds(this->interval - milli_diff));
            milli_diff = this->interval;
        }

        last_time = time_start;

        //Run all triggers
        for (auto &kv : this->intervals)
        {
            IntervalBatch &batch = kv.second;
            if (time_start - batch.last_called >= kv.first)
            { //Check interval
                batch.last_called = time_start;
                for (auto trigger : batch.triggers)
                {
                    trigger->onCheck(time_start, milli_diff);
                }
            }
        }

        //Process all events
        for (auto &event : this->events)
        {
            event.callback->onTrigger(event.variables);
        }
        this->events.clear();
    }
}

void EventQueue::runLoop()
{
    this->runLoop(30);
}


void EventQueue::stop(){
    Logger::getLogger()->debug("Stopping event queue");
    this->running = false;
}

EventQueue *EventQueue::getInstance()
{
    static EventQueue *instance = new EventQueue();
    return instance;
}