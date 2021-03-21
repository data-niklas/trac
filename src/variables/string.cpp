#include "./string.h"

String::String(string value){
    this->value = value;
}

#include <iostream>

String::~String(){
}

string String::asString(){
    return this->value;
}