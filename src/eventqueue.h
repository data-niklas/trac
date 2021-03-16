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
    std::map<long, std::vector<Trigger *>> intervals;
    bool running;
    std::mutex mutex;
};