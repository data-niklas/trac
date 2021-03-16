#include "./call.h"
#include "../registry.h"

Call::Call(std::string name, std::vector<Variable*> variables){
    Registry* registry = Registry::getInstance();
    //TODO Error Management
    this->function = registry->gFunction(name);
    this->variables = variables;
}

Variable* Call::execute(Context* context){
    std::vector<Variable*> variables;
    for(auto var : this->variables){
        if (var->isExecutable()){
            variables.push_back(var->execute(context));
        }
        else{
            variables.push_back(var);
        }
    }
    return this->function->call(variables);
}

std::string Call::getName(){
    return this->function->getName();
}

bool Call::isExecutable(){
    return true;
}