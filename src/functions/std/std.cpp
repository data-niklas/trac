#include "./std.h"
#include "./string.h"


void registerUtil(Registry* r){

}

void registerStd(Registry* r){
    registerUtil(r);
    registerString(r);
}