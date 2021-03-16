#pragma once

#include <string>

class Context;

class Variable{
    public:
        virtual std::string asString(){
            return "variable";
        }
        virtual Variable* execute(Context* context){
            return this;
        }
        virtual bool isExecutable(){
            return false;
        }
};