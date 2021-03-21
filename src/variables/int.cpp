#include "./int.h"

Int::Int(long value){
    this->value = value;
}


Int::~Int(){
}

string Int::asString(){
    return to_string(this->value);
}