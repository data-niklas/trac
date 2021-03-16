#include "./xlib.h"

XLibListener::XLibListener(XLibCallback callback, SimpleTrigger *trigger)
{
    this->callback = callback;
    this->trigger = trigger;
}

XLib::XLib()
{
    this->dpy = XOpenDisplay(NULL);
    this->root = XDefaultRootWindow(this->dpy);
    EventQueue::getInstance()->registerTick(this);
}
XLib::~XLib()
{
    this->mask = 0;
    XCloseDisplay(this->dpy);
}

XLib *XLib::getInstance()
{
    static XLib *instance = new XLib();
    return instance;
}
void XLib::registerListener(XLibCallback callback, long mask, SimpleTrigger *trigger)
{
    this->listeners.push_back(XLibListener(callback, trigger));
    this->mask |= mask;
    XSelectInput(this->dpy, this->root, this->mask);
}
void XLib::onCheck(long time, long millidiff)
{
    while (XPending(this->dpy))
    {
        XEvent event;
        XNextEvent(this->dpy, &event);
        for (auto listener : this->listeners)
        {
            listener.callback(event, listener.trigger);
        }
    }
}

unsigned char *XLib::getProperty(Window window, Atom atom, long max_length,
                                 unsigned long *nitems_return, unsigned char **prop_return)
{
    int result;
    Atom actual_type_return;
    int actual_format_return;
    unsigned long bytes_after_return;
    unsigned char *prop_to_return;
    unsigned long n_items;

    result = XGetWindowProperty(this->dpy, window, atom, 0, /* long_offset */
                                (~0L),                        /* long_length */
                                False,                        /* delete */
                                AnyPropertyType,              /* req_type */
                                &actual_type_return,
                                &actual_format_return,
                                &n_items, &bytes_after_return, &prop_to_return);
    if (result != Success)
    {
        return nullptr;
    }
    else
    {
        return prop_to_return;
    }
}

Window XLib::getWindowProperty(Window window, Atom atom)
{
    unsigned long nitems_return;
    unsigned char* prop_return;
    unsigned char* result = this->getProperty(window, atom, 10000, &nitems_return, &prop_return);
    return ((Window*)result)[0];
}