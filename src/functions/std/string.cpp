#include "./string.h"

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

void print(shared_ptr<Variable> var)
{
    if (shared_ptr<String> v = dynamic_pointer_cast<String>(var))
    {
        cout << v->value;
    }
    else if (shared_ptr<Int> v = dynamic_pointer_cast<Int>(var))
    {
        cout << v->value;
    }
    else if (shared_ptr<Float> v = dynamic_pointer_cast<Float>(var))
    {
        cout << v->value;
    }
    else if (shared_ptr<Boolean> v = dynamic_pointer_cast<Boolean>(var))
    {
        cout << (v->value ? "true" : "false");
    }
    else if (shared_ptr<Void> v = dynamic_pointer_cast<Void>(var))
    {
    }
}

void println(shared_ptr<Variable> var)
{
    print(var);
    cout << '\n';
}

shared_ptr<Variable> formatTime(vector<shared_ptr<Variable>> params)
{
    if (params.size() == 2)
    {
        if (IS_TYPE(Int, time, params[0]))
        {
            if (IS_TYPE(String, format, params[1]))
            {
                const time_t timeins = time->value / 1000;
                stringstream buffer;
                buffer << put_time(localtime(&timeins), format->value.c_str());
                return shared_ptr<Variable>(new String(buffer.str()));
            }
            else
                throw InvalidType("String", "function format_time");
        }
        else
            throw InvalidType("Int", "function format_time");
    }
    else
        throw InvalidArguments(2, params.size(), "function format_time");
}

shared_ptr<Variable> toString(vector<shared_ptr<Variable>> params)
{
    if (params.size() == 1)
    {
        if (IS_TYPE(Boolean, var, params[0]))
        {
            return shared_ptr<String>(new String(var->value ? "true" : "false"));
        }
        else if (IS_TYPE(Float, var, params[0]))
        {
            return shared_ptr<String>(new String(to_string(var->value)));
        }
        else if (IS_TYPE(Int, var, params[0]))
        {
            return shared_ptr<String>(new String(to_string(var->value)));
        }
        else if (IS_TYPE(String, var, params[0]))
        {
            return params[0];
        }
        else if (IS_TYPE(Void, var, params[0]))
        {
            return shared_ptr<String>(new String(""));
        }
        return Void::noreturn();
    }
    else
        throw InvalidArguments(1, params.size(), "function string");
}

shared_ptr<Variable> println(vector<shared_ptr<Variable>> vars)
{
    for (auto var : vars)
    {
        println(var);
    }
    return Void::noreturn();
}

shared_ptr<Variable> print(vector<shared_ptr<Variable>> vars)
{
    for (auto var : vars)
    {
        print(var);
    }
    return Void::noreturn();
}

void registerString(Registry *r)
{
    r->rFunction(new Function("format_time", formatTime));
    r->rFunction(new Function("println", println));
    r->rFunction(new Function("print", print));
}