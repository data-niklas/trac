#include "./std.h"
#include "./string.h"
#include "./operators.h"

void registerUtil(Registry *r)
{
    r->rFunction(new Function("", [](vector<shared_ptr<Variable>> vars) -> shared_ptr<Variable> {
        return Void::noreturn();
    }));
    r->rFunction(new Function("run", [](vector<shared_ptr<Variable>> params) -> shared_ptr<Variable> {
        if (params.size() >= 1)
        {
          std::string command = "";
            for (auto it = params.begin(); it != params.end(); ++it) {
                if (IS_TYPE(String, command_arg, *it)){
                  if (it != params.begin())
                    command += " ";
                  command += command_arg->value;
                }
                else throw InvalidType("String", "function run");
            }

            system(command.c_str());
            return Void::noreturn();
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
