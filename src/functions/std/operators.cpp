#include "./operators.h"

shared_ptr<Variable> eq(vector<shared_ptr<Variable>> params)
{
    if (params.size() == 2)
    {
        if (IS_TYPE(Boolean, var, params[0]))
        {
            if (IS_TYPE(Boolean, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Float, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Int, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(String, var, params[0]))
        {
            if (IS_TYPE(String, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value == var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Void, var, params[0]))
        {
            if (IS_TYPE(Void, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(true));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else
            return shared_ptr<Boolean>(new Boolean(false));
    }
    else
        throw InvalidArguments(2, params.size(), "function eq");
}

shared_ptr<Variable> neq(vector<shared_ptr<Variable>> params)
{
    if (IS_TYPE(Boolean, var, eq(params)))
    {
        return shared_ptr<Boolean>(new Boolean(!var->value));
    }
    else
    {
        throw InvalidType("Boolean", "function neq");
    }
}

shared_ptr<Variable> gt(vector<shared_ptr<Variable>> params)
{
    if (params.size() == 2)
    {
        if (IS_TYPE(Boolean, var, params[0]))
        {
            if (IS_TYPE(Boolean, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Float, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Int, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(String, var, params[0]))
        {
            if (IS_TYPE(String, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value > var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Void, var, params[0]))
        {
            if (IS_TYPE(Void, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(true));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else
            return shared_ptr<Boolean>(new Boolean(false));
    }
    else
        throw InvalidArguments(2, params.size(), "function gt");
}

shared_ptr<Variable> lt(vector<shared_ptr<Variable>> params)
{
    if (params.size() == 2)
    {
        if (IS_TYPE(Boolean, var, params[0]))
        {
            if (IS_TYPE(Boolean, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Float, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Int, var, params[0]))
        {
            if (IS_TYPE(Float, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else if (IS_TYPE(Int, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(String, var, params[0]))
        {
            if (IS_TYPE(String, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(var->value < var2->value));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else if (IS_TYPE(Void, var, params[0]))
        {
            if (IS_TYPE(Void, var2, params[1]))
            {
                return shared_ptr<Boolean>(new Boolean(true));
            }
            else
                return shared_ptr<Boolean>(new Boolean(false));
        }
        else
            return shared_ptr<Boolean>(new Boolean(false));
    }
    else
        throw InvalidArguments(2, params.size(), "function lt");
}

shared_ptr<Variable> geq(vector<shared_ptr<Variable>> params)
{
    if (IS_TYPE(Boolean, var, eq(params)))
    {
        if (IS_TYPE(Boolean, var2, gt(params)))
        {
            return shared_ptr<Boolean>(new Boolean(var->value && var2->value));
        }
        else
        {
            throw InvalidType("Boolean", "function geq");
        }
        return shared_ptr<Boolean>(new Boolean(!var->value));
    }
    else
    {
        throw InvalidType("Boolean", "function geq");
    }
}

shared_ptr<Variable> leq(vector<shared_ptr<Variable>> params)
{
    if (IS_TYPE(Boolean, var, eq(params)))
    {
        if (IS_TYPE(Boolean, var2, leq(params)))
        {
            return shared_ptr<Boolean>(new Boolean(var->value && var2->value));
        }
        else
        {
            throw InvalidType("Boolean", "function leq");
        }
        return shared_ptr<Boolean>(new Boolean(!var->value));
    }
    else
    {
        throw InvalidType("Boolean", "function leq");
    }
}

void registerOperators(Registry *r)
{
    r->rFunction(new Function("=", eq));
    r->rFunction(new Function("eq", eq));
    r->rFunction(new Function("!", neq));
    r->rFunction(new Function("neq", neq));
    r->rFunction(new Function("<", lt));
    r->rFunction(new Function("lt", lt));
    r->rFunction(new Function(">", gt));
    r->rFunction(new Function("gt", gt));
    r->rFunction(new Function(">=", geq));
    r->rFunction(new Function("geq", geq));
    r->rFunction(new Function("<=", leq));
    r->rFunction(new Function("leq", leq));
}