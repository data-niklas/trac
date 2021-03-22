#include "./void.h"


string Void::asString(){
    return "void";
}

shared_ptr<Void> Void::noreturn(){
    static shared_ptr<Void> var = shared_ptr<Void>(new Void());
    return var;
}