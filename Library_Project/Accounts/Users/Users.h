#ifndef LIBRARY_SYSTEM_PROJECT_USERS_H
#define LIBRARY_SYSTEM_PROJECT_USERS_H
#pragma once
#include "Users.h"
#include "../Roles.h"
#include <iostream>
#include <string>
using namespace std;

class Users {
protected:
    string username;
    string password;
    string role_;
protected:
    Roles _userRoles;
public:
    // Constructors & Constructor overloading handling here
    Users();
    explicit Users(const string&);
    Users(const string &, const string&);
    Users(const string&, const string&, const string&);
public:
    // Getters & Setters
    string get_username();
    string get_password();
    string get_role_input();
};


#endif //LIBRARY_SYSTEM_PROJECT_USERS_H
