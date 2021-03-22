#include "./notfound.h"

NotFound::NotFound(string notfound, string where) : TracError(where){
    this->notfound = notfound;
}

const void NotFound::print(){
    Logger::getLogger()->error(this->notfound + " does not exist in " + this->where);
}