#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Variable;

class Context{
    public:
        bool has(string name);
        void set(string name, shared_ptr<Variable> var);
        void erase(string name);
        shared_ptr<Variable> get(string name);

    private:
        map<string, shared_ptr<Variable>> variables;
};