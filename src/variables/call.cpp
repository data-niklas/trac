#include "./call.h"
#include "../registry.h"

Call::Call(string name, vector<shared_ptr<Variable>> variables){
    Registry* registry = Registry::getInstance();
    //TODO Error Management
    this->function = registry->gFunction(name);
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