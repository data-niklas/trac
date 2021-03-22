#include "./xlibfunctions.h"

#include "../libraries/xlib.h"
#include "../variables/literal.h"

#include <string>

void registerXLibFunctions(Registry* r){
    r->rFunction(new Function("window_name",[](vector<shared_ptr<Variable>> variables)->shared_ptr<Variable>{
        XLib * xlib = XLib::getInstance();
        shared_ptr<Variable> var = variables[0];
        if (shared_ptr<Int> intvalue = dynamic_pointer_cast<Int>(var)){
                Window window = intvalue->value;
                if (window == 0){
                    return Void::noreturn();
                }
                XTextProperty prop;
                XGetWMName(xlib->dpy, window, &prop);
                return shared_ptr<Variable>(new String(string((char*)prop.value)));
        }
        return Void::noreturn();
    }));

    r->rFunction(new Function("is_active",[](vector<shared_ptr<Variable>> variables)->shared_ptr<Variable>{
        XLib * xlib = XLib::getInstance();
        static Atom ACTIVE_WINDOW = XInternAtom(xlib->dpy, "_NET_ACTIVE_WINDOW",false);

        Window window = xlib->getWindowProperty(xlib->root, ACTIVE_WINDOW);
        if (variables.size() != 1)return shared_ptr<Variable>(new Boolean(false));
        else if (shared_ptr<Int> var = dynamic_pointer_cast<Int>(variables[0])){
            return shared_ptr<Variable>(new Boolean(window == (long unsigned int)var->value));
        }
        else return Void::noreturn();
    }));
}