#include "./list.h"

List::List(std::vector<shared_ptr<Variable>> value){
    this->value = value;
}

List::~List(){
}

string List::asString(){
    string result = "[ ";
    if (this->value.size() != 0)result += this->value[0]->asString();
    for (long unsigned int i = 1; i < this->value.size(); i++){
        result += ", ";
        result += this->value[i]->asString();
    }
    return result + "]";
}