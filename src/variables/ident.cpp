#include "./ident.h"
#include "./string.h"

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
    if (this->value.rfind("$",0) == 0){
        return shared_ptr<String>(new String(string(getenv(this->value.c_str() + 1))));
    }
    else return context->get(this->value);
}