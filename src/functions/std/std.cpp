#include "./std.h"
#include "./string.h"

void print(shared_ptr<Variable> var){
    if (shared_ptr<String> v = dynamic_pointer_cast<String>(var)){
        cout << v->value;
    }
    else if (shared_ptr<Int> v = dynamic_pointer_cast<Int>(var)){
        cout << v->value;
    }
    else if (shared_ptr<Boolean> v = dynamic_pointer_cast<Boolean>(var)){
        cout << (v->value ? "true" : "false");
    }
    else if (shared_ptr<Void> v = dynamic_pointer_cast<Void>(var)){
 
    }
}

void println(shared_ptr<Variable> var){
    print(var);
    cout << '\n';
}

void registerUtil(Registry* r){
    r->rFunction(new Function("println",[](vector<shared_ptr<Variable>> vars)->shared_ptr<Variable>{
        for (auto var : vars){
           println(var);
        }
        return shared_ptr<Variable>(new Void());
    }));
    r->rFunction(new Function("print",[](vector<shared_ptr<Variable>> vars)->shared_ptr<Variable>{
        for (auto var : vars){
           print(var);
        }
        return shared_ptr<Variable>(new Void());
    }));
}

void registerStd(Registry* r){
    registerUtil(r);
    registerString(r);
}