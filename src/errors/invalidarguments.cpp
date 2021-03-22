#include "./invalidarguments.h"

InvalidArguments::InvalidArguments(int expected, int actual, string where) : TracError(where){
    this->expected = expected;
    this->actual = actual;
}

const void InvalidArguments::print(){
    Logger::getLogger()->error("Expected " + to_string(this->expected) + " arguments, but found " + to_string(this->actual) + " in " + this->where);
}