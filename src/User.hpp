#pragma once
#include <string>

using std::string;

class User {
    public:
    unsigned long id;
    string name;
    string email;
    User(unsigned long id, string name, string email);
};
