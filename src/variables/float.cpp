#include "./float.h"

Float::Float(double value){
    this->value = value;
}

Float::~Float(){
}

string Float::asString(){
    return to_string(this->value);
}