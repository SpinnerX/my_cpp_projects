#include "Users.h"
using namespace std;

Users::Users() { }

Users::Users(const string &_usernameInput) {
    username = _usernameInput;
}

Users::Users(const string &_usernameInput, const string &_passwordInput) {
    username = _usernameInput;
    password = _passwordInput;
}

Users::Users(const string &_usernameInput, const string &_passwordInput, const string &role_type) {
    username = _usernameInput;
    password = _passwordInput;
    role_ = role_type;
}

string Users::get_username() {
    return username;
}

string Users::get_password() {
    return password;
}

string Users::get_role_input() {
    return role_;
}