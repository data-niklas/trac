#pragma once

#include <string>
#include <memory>

using namespace std;

class Context;

#define IS_TYPE(type, name, var) shared_ptr<type> name = dynamic_pointer_cast<type>(var)

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