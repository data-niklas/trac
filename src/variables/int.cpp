#include "./int.h"

Int::Int(long value){
    this->value = value;
}

std::string Int::asString(){
    return std::to_string(this->value);
}