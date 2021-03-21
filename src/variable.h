#pragma once

#include <string>
#include <memory>

using namespace std;

class Context;

class Variable{
    public:
        virtual ~Variable(){}
        virtual string asString(){
            return "variable";
        }
        virtual shared_ptr<Variable> execute(Context* context){
            return shared_ptr<Variable>(this);
        }
        virtual bool isExecutable(){
            return false;
        }
};