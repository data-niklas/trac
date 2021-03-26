#include "./boolean.h"


Boolean::Boolean(bool value){
    this->value = value;
}

string Boolean::asString(){
    return to_string(this->value);
}
Boolean::~Boolean(){
}