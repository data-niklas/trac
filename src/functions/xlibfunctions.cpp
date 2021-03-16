#include "./xlibfunctions.h"

#include "../libraries/xlib.h"
#include "../variables/literal.h"

#include <string>

void registerXLibFunctions(Registry* r){
    r->rFunction(new Function("window_name",[](std::vector<Variable*> variables)->Variable*{
        XLib * xlib = XLib::getInstance();
        Variable *var = variables[0];
        if (Int *intvalue = dynamic_cast<Int*>(var)){
                Window window = intvalue->value;
                if (window == 0){
                    return new Void();
                }
                XTextProperty prop;
                XGetWMName(xlib->dpy, window, &prop);
                return new String(std::string((char*)prop.value));
        }
        return new Void();
    }));

    r->rFunction(new Function("is_active",[](std::vector<Variable*> variables)->Variable*{
        XLib * xlib = XLib::getInstance();
        static Atom ACTIVE_WINDOW = XInternAtom(xlib->dpy, "_NET_ACTIVE_WINDOW",false);

        Window window = xlib->getWindowProperty(xlib->root, ACTIVE_WINDOW);
        if (variables.size() != 1)return new Boolean(false);
        else if (Int* var = dynamic_cast<Int*>(variables[0])){
            return new Boolean(window == var->value);
        }
    }));
}