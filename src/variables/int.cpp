#include "./int.h"

Int::Int(long value){
    this->value = value;
}

#include <iostream>

Int::~Int(){
}

string Int::asString(){
    return to_string(this->value);
}