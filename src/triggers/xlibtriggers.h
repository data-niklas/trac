#pragma once
#include <climits>
#include <string.h>

#include "./simpletrigger.h"
#include "../libraries/xlib.h"
#include "../variables/int.h"

class ActiveWindowChangeTrigger : public SimpleTrigger
{
public:
    ActiveWindowChangeTrigger(Trac* callback) : SimpleTrigger(callback)
    {
        XLib *xlib = XLib::getInstance();
        xlib->registerListener([](XEvent event, SimpleTrigger *trigger) {
            XLib *xlib = XLib::getInstance();
            if (event.type == PropertyNotify && event.xproperty.state == 0)
            {
                Atom atom = event.xproperty.atom;
                if (!strcmp(XGetAtomName(xlib->dpy, atom), "_NET_ACTIVE_WINDOW"))
                {
                    Atom actualType;
                    int actualFormat;
                    unsigned long nItems, bytesAfter;
                    unsigned char *value;
                    int res;
                    if ((res = XGetWindowProperty(xlib->dpy, xlib->root, atom, 0, LONG_MAX / 4,
                                           False, XA_WINDOW,
                                           &actualType, &actualFormat,
                                           &nItems, &bytesAfter, &value)) == Success &&
                        actualType == XA_WINDOW)
                    {
                        Window result = *(Window *)value; /*  <=== this line seems dubious */
                        XFree(value);
                        vector<shared_ptr<Variable>> variables;
                        variables.push_back(shared_ptr<Variable>(new Int(result))); 
                        trigger->trigger(variables);         
                    }
                }
            }
        }, PropertyChangeMask, this);
    }
};