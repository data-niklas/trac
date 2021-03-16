#include "./context.h"

bool Context::has(std::string name){
    return this->variables.count(name) > 0;
}
void Context::set(std::string name, Variable* var){
    this->variables[name] = var;
}
void Context::erase(std::string name){
    this->variables.erase(name);
}

Variable* Context::get(std::string name){
    return this->variables[name];
}