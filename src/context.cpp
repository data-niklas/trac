#include "./context.h"

bool Context::has(string name){
    return this->variables.count(name) > 0;
}
void Context::set(string name, shared_ptr<Variable> var){
    this->variables[name] = var;
}
void Context::erase(string name){
    this->variables.erase(name);
}

shared_ptr<Variable> Context::get(string name){
    return this->variables[name];
}