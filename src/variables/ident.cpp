#include "./ident.h"

Ident::Ident(string value){
    this->value = value;
}

string Ident::asString(){
    return this->value;
}
bool Ident::isExecutable(){
    return true;
}
shared_ptr<Variable> Ident::execute(Context* context){
    return context->get(this->value);
}