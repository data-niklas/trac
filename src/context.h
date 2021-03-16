#pragma once

#include <map>
#include <vector>
#include <string>

class Variable;

class Context{
    public:
        bool has(std::string name);
        void set(std::string name, Variable* var);
        void erase(std::string name);
        Variable* get(std::string name);

    private:
        std::map<std::string, Variable*> variables;
};