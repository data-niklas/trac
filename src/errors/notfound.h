#pragma once

#include "../error.h"

class NotFound : public TracError{
    public:
        NotFound(string notfound, string where);

        const void print();
        string notfound;
};