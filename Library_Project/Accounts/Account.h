#ifndef LIBRARY_SYSTEM_PROJECT_ACCOUNT_H
#define LIBRARY_SYSTEM_PROJECT_ACCOUNT_H
#pragma once
#include "Users/Users.h"
#include "Account.h"
#include "Roles.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/*
 * - Account class handling users login
 * - Handling encryption and decryption operations
 * - Handling ways passwords and usernames input
*/

class Account : Users{
public:
    // Encrypting passwords and usernames
    // Decrypting passwords and usernames
    static string encrypting_info(string&);
    string decrypting_info(string&);
public:
    // Roles final_loading_login_information(string&, string&);
    // Initializing create account & login functionalities
    string choose_role(int create_role); // Choosing type of role for the user

public:
    Roles loading_save_user_role(string &compare_roles); // Loading user roles from saved file

    // Version 2
    // Roles loading_login_information_2(string&, string&);
};


#endif //LIBRARY_SYSTEM_PROJECT_ACCOUNT_H
