#pragma once

#include "../error.h"

class InvalidArguments : public TracError{
    public:
        InvalidArguments(int expected, int actual, string where);
        int expected, actual;
        const void print();
};