#include "./call.h"
#include "../registry.h"
#include "../logger.h"

Call::Call(string name, vector<shared_ptr<Variable>> variables){
    Registry* registry = Registry::getInstance();
    
    if (registry->eFunction(name))this->function = registry->gFunction(name);
    else {
        this->function = registry->gFunction("");
        Logger::getLogger()->error("Function " + name + " does not exist");
    }
    this->variables = variables;
}

shared_ptr<Variable> Call::execute(Context* context){
    vector<shared_ptr<Variable>> variables;
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

string Call::getName(){
    return this->function->getName();
}

bool Call::isExecutable(){
    return true;
}