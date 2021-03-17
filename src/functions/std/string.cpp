#include "./string.h"
#include "../../variables/literal.h"
#include "../../function.h"

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>




Variable* formatTime(std::vector<Variable*> params){
    if (params.size() == 2){
        if (Int* time = dynamic_cast<Int*>(params[0])){
            if (String* format = dynamic_cast<String*>(params[1])){
                const time_t timeins = time->value / 1000;
                std::stringstream buffer;
                buffer << std::put_time(std::localtime(&timeins), format->value.c_str());
                return new String(buffer.str());
            }
        }
    }
    return new Void();
}

void registerString(Registry* r){
    r->rFunction(new Function("format_time",formatTime));
}