#include "./string.h"

String::String(std::string value){
    this->value = value;
}

std::string String::asString(){
    return this->value;
}