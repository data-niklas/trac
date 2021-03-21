#include "./string.h"
#include "../../variables/literal.h"
#include "../../function.h"

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>




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

void registerString(Registry* r){
    r->rFunction(new Function("format_time",formatTime));
}