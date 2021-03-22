#pragma once

#include <exception>
#include <string>
using namespace std;

#include "./logger.h"

class TracError : public exception{
    public:
        TracError(string where);
        virtual const void print(){}
        string where;
};