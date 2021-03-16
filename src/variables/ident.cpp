#include "./ident.h"

Ident::Ident(std::string value){
    this->value = value;
}

std::string Ident::asString(){
    return this->value;
}
bool Ident::isExecutable(){
    return true;
}
Variable* Ident::execute(Context* context){
    return context->get(this->value);
}