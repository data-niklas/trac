#include "./string.h"
#include "../../variables/literal.h"
#include "../../function.h"

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>


void print(shared_ptr<Variable> var){
    if (shared_ptr<String> v = dynamic_pointer_cast<String>(var)){
        cout << v->value;
    }
    else if (shared_ptr<Int> v = dynamic_pointer_cast<Int>(var)){
        cout << v->value;
    }
    else if (shared_ptr<Float> v = dynamic_pointer_cast<Float>(var)){
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

shared_ptr<Variable> formatTime(vector<shared_ptr<Variable>> params){
    if (params.size() == 2){
        if (shared_ptr<Int> time = dynamic_pointer_cast<Int>(params[0])){
            if (shared_ptr<String> format = dynamic_pointer_cast<String>(params[1])){
                const time_t timeins = time->value / 1000;
                stringstream buffer;
                buffer << put_time(localtime(&timeins), format->value.c_str());
                return shared_ptr<Variable>(new String(buffer.str()));
            }
        }
    }
    return shared_ptr<Variable>(new Void());
}

shared_ptr<Variable> println(vector<shared_ptr<Variable>> vars){
    for (auto var : vars){
        println(var);
    }
    return shared_ptr<Variable>(new Void());
}

shared_ptr<Variable> print(vector<shared_ptr<Variable>> vars){
    for (auto var : vars){
        print(var);
    }
    return shared_ptr<Variable>(new Void());
}

void registerString(Registry* r){
    r->rFunction(new Function("format_time",formatTime));
    r->rFunction(new Function("println",println));
    r->rFunction(new Function("print",print));
}