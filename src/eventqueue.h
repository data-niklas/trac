#pragma once

#include <vector>
#include <map>
#include <sys/time.h>
#include <chrono>
#include <thread>
#include <mutex>

#include "./trigger.h"
#include "./trac.h"

class Event
{
    public:
        Event(Trac* callback, std::vector<Variable*> variables);
        Trac* callback;
        
        std::vector<Variable*> variables;
    private:
};


class IntervalBatch{
    public:
        IntervalBatch();
        std::vector<Trigger *> triggers;
        long last_called;
};

class EventQueue
{
public:
    void addEvent(Event event);
    void registerTick(Trigger *trigger);
    void registerInterval(Trigger *trigger, long interval);

    void runLoop();

    static EventQueue *getInstance();

private:
    std::vector<Event> events;
    std::map<long, IntervalBatch> intervals;
    bool running;
    std::mutex mutex;
};