#include "Accounts/Account.h"
#include <iostream>
#include <vector>
using namespace std;

void admin_main_menu(){
    cout << "1. Add Book" << endl
         << "2. Remove Book" << endl
         << "3. List all checked out books" << endl
         << "4. List all books" << endl
         << "5. Check Out Book" << endl
         << "6. Check In Book" << endl
         << "0. Leave Library" << endl;
}

void member_main_menu(){
    cout << "1. List all books" << endl
         << "2. Check Out Book" << endl
         << "3. Check In Book" << endl

         << "0. Leave Library" << endl;
}

// Main menu that displays depending on users role
void main_menu(Roles compare_roles){

    if (compare_roles == Roles::Admin || compare_roles == Roles::Employee) {
        admin_main_menu();
    }
    if (compare_roles == Roles::Member) {
        member_main_menu();
    }
}

// Create user accounts/new file
void create_account(Account &_users){
    cin.ignore();

    string username;
    string password;
    int role_choice;

    cout << "Enter new username: ";
    getline(cin, username);

    cout << "Enter new password: ";
    getline(cin, password);

    cout << "0. Admin" << endl
         << "1. Employee" << endl
         << "2. Member" << endl
         << "Enter option: ";
    cin >> role_choice;

    const string filepath = "/Users/aaronher/CLionProjects/Github_Projects/my_cpp_projects/Library_Project//Accounts/Users/user_files/" + username;
    ofstream new_account(filepath);

    // new_account << "Username: " << username << endl;
    // new_account << "Password: " << password << endl;
    // Encrypting passwords and usernames here
    new_account << "Username: " << Account::encrypting_info(username) << endl;
    new_account << "Password: " << Account::encrypting_info(password) << endl;
    new_account << "Role: " << _users.choose_role(role_choice);
    new_account.close();
}

void login(Account &_users){
    string check_pass, check_role_input;
    string username, password, search_role;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >>check_pass;

    const string filepath = "/Users/aaronher/CLionProjects/Github_Projects/my_cpp_projects/Library_Project//Accounts/Users/user_files/" + username;

    ifstream load_account(filepath, ios::binary); // opening file for input


    // Checking if file opened
    if (!load_account){
        cout << "(load acct)Username not found!" << endl;
    }

    // vector of accounts
    vector<Users> users_acct;
    string textLine; // contain text of each line in the file

    // continuing iterating through each line in file
    while(getline(load_account, textLine)){
        if (textLine.empty()){ // Checking if theres no text
            continue;
        }

        auto iterated = textLine.find(' '); // Finding empty string

        // checking if iterator is not the string::npos
        if (iterated != string::npos){

            // Search individual lines here
            // Specific lines in the file
            // With variables to contain information
            username = textLine.substr(0, iterated);
            password = textLine.substr(iterated+1, string::npos);
            search_role = textLine.substr(iterated+1, string::npos);

            Users _acct = {username, password, search_role};

            users_acct.push_back(_acct);
        }
    }

    // Using for-each loop to iterate vector
    // comparing usernames and passwords here
    for (Users &read_account : users_acct) {

        // Comparing username and password input with the object read_account information
        if (_users.decrypting_info(username) == username && _users.decrypting_info(password) == password) {
            cout << "Enter your role number: ";
            cin >> check_role_input;

            // Compare roles based on users input here
            if (_users.decrypting_info(search_role) == check_role_input){
                main_menu(_users.loading_save_user_role(check_role_input));
                break;
            }
            else {
                cout << "Not the right role here!" << endl;
                break;
            }
        }
    }
}

int main() {

    int user_option;
    Account _rootUser_Account;
    cout << "1. login" << endl
         << "2. Create Account" << endl
         << "Enter option: ";
    cin >> user_option;

    switch(user_option){
        case 1:
            // login(_rootUser_Account);
            login(_rootUser_Account);
            break;
        case 2:
            create_account(_rootUser_Account);
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
    }

    return 0;
}