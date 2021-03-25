#include "Account.h"
using namespace std;

string Account::encrypting_info(string &input) {
    for (int i = 0; (i < 100 && input[i] != '\0'); i++)
        input[i] = input[i] + 2; // Key for encryption +3 added to ASCII value
    return input;
}

string Account::decrypting_info(string &login_information) {
    for (int i = 0; (i < 100 && login_information[i] != '\0'); i++) {
        login_information[i] = login_information[i] - 2;
    }
    // cout << login_information << endl;
    return login_information;
}

string Account::choose_role(int create_role) {
    string contain_role;

    if (create_role == 0)
        contain_role = "Admin";
    else if (create_role == 1)
        contain_role = "Employee";
    else
        contain_role = "Member";

    return Account::encrypting_info(contain_role);
}

Roles Account::loading_save_user_role(string &compare_roles) {

    if (compare_roles == "Admin")
        _userRoles = Roles::Admin;
    else if (compare_roles == "Employee")
        _userRoles = Roles::Employee;
    else
        _userRoles = Roles::Member;
    return _userRoles;
}
