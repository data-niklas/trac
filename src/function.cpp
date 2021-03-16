#include "./function.h"

Function::Function(std::string name, FunctionCallback callback){
    this->callback = callback;
    this->name = name;
}

Variable* Function::call(std::vector<Variable*> vars){
    return this->callback(vars);
}

std::string Function::getName(){
    return this->name;
}