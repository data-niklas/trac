#pragma once

#include "../variable.h"

class Void : public Variable{
    public:
        string asString();
        static shared_ptr<Void> noreturn();
};