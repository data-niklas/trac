#include "./std.h"
#include "./string.h"


void registerUtil(Registry* r){
    r->rFunction(new Function("",[](vector<shared_ptr<Variable>> vars)->shared_ptr<Variable>{
        return Void::noreturn();
    }));
}

void registerStd(Registry* r){
    registerUtil(r);
    registerString(r);
}