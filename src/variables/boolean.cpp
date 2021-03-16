#include "./boolean.h"


Boolean::Boolean(bool value){
    this->value = value;
}

std::string Boolean::asString(){
    return std::to_string(this->value);
}