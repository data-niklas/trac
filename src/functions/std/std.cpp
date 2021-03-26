#include "./std.h"
#include "./string.h"
#include "./operators.h"

void registerUtil(Registry *r)
{
    r->rFunction(new Function("", [](vector<shared_ptr<Variable>> vars) -> shared_ptr<Variable> {
        return Void::noreturn();
    }));
    r->rFunction(new Function("run", [](vector<shared_ptr<Variable>> params) -> shared_ptr<Variable> {
        if (params.size() == 1)
        {

            if (IS_TYPE(String, var, params[0]))
            {
                system(var->value.c_str());
                return Void::noreturn();
            }
            else throw InvalidType("String", "function run");
        }
        else
            throw InvalidArguments(1, params.size(), "function run");
    }));
}

void registerStd(Registry *r)
{
    registerUtil(r);
    registerString(r);
    registerOperators(r);
}