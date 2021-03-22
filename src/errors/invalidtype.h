#pragma once

#include "../error.h"

class InvalidType : public TracError{
    public:
        InvalidType(string expected, string where);
        string expected;
        const void print();
};