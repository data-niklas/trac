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
        Event(Trac* callback, vector<shared_ptr<Variable>> variables);
        Trac* callback;
        
        vector<shared_ptr<Variable>> variables;
    private:
};


class IntervalBatch{
    public:
        IntervalBatch();
        vector<Trigger *> triggers;
        long last_called;
};

class EventQueue
{
public:
    void addEvent(Event event);
    void registerTick(Trigger *trigger);
    void registerInterval(Trigger *trigger, long interval);

    void runLoop();
    void runLoop(long interval);
    void stop();

    static EventQueue *getInstance();

private:
    vector<Event> events;
    map<long, IntervalBatch> intervals;
    bool running;
    long interval;
    mutex queue_lock;
};