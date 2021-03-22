#include "./invalidtype.h"

InvalidType::InvalidType(string expected, string where) : TracError(where){
    this->expected = expected;
}

const void InvalidType::print(){
    Logger::getLogger()->error("Expected type " + this->expected  + " in " + this->where);
}