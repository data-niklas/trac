#pragma once

#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xinerama.h>

#include <map>
#include <vector>

#include "../trigger.h"
#include "../eventqueue.h"
#include "../triggers/simpletrigger.h"

typedef void (*XLibCallback)(XEvent, SimpleTrigger*);

class XLibListener
{
public:
    XLibListener(XLibCallback callback, SimpleTrigger* trigger);
    XLibCallback callback;
    SimpleTrigger* trigger;
};



class XLib : public Trigger
{

public:
    Display *dpy;
    Window root;
    vector<XLibListener> listeners;
    long mask;

    XLib();
    ~XLib();

    static XLib *getInstance();
    void registerListener(XLibCallback callback, long mask, SimpleTrigger* trigger);
    void onCheck(long time, long millidiff);

    unsigned char* getProperty(Window window, Atom atom, long max_length,
           unsigned long *nitems_return, unsigned char **prop_return);
    Window getWindowProperty(Window window, Atom atom);

};
