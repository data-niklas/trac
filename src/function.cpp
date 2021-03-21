#include "./function.h"

Function::Function(string name, FunctionCallback callback){
    this->callback = callback;
    this->name = name;
}

shared_ptr<Variable> Function::call(vector<shared_ptr<Variable>> vars){
    return this->callback(vars);
}

string Function::getName(){
    return this->name;
}