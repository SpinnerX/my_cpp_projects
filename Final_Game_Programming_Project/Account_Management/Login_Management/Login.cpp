#include "Login.h"
#include <fstream>
#include <sstream>
using namespace std;

Login::Login() {
    logging_ing_player = Player();
    filepath = "";
}

Login::Login(string &username, string &password) {
    // this->username = username;
    // this->password = password;
    logging_ing_player = Player(username, password);
    filepath = "/Users/aaronher/C++_Folder/Projects/Final_(Game_Programming)_Remastered_2/Player_Accounts/" + username;
}

bool Login::login_check() {
    string _username;
    string _password;

    ifstream readFile(filepath);

    // Checking if files not opened!
    if(!readFile.is_open()){
        cout << "Username cannot be found!" << endl;
        return false;
    }

    string each_line;

    // Iterating line by line through given filename/filepath
    while(getline(readFile, each_line)) {


        // Search for any whitespaces between strings/char
        auto str_iterator = each_line.find(' ');

        if (str_iterator != string::npos) {
            // Iterating through each line in the file
            _username = each_line.substr(str_iterator + 1, string::npos); // Username Line Found Here
            _password = each_line.substr(str_iterator + 1, string::npos);
        }

        // Checking players username and password
        if(logging_ing_player.player_username() == _username){
            continue;
        }
        if(logging_ing_player.player_password() == _password){
            return true;
        }

        if (each_line.empty()){ printf("Player does not exist!"); break; }
    }
    return false;
}

void Login::players_info() {

    string each_line;

    ifstream readFile(filepath);

    while(getline(readFile, each_line)){
        cout << each_line << endl;
    }

    if(!readFile.is_open()) { printf("Player cannot be found!\n"); }

    /*string _username;
    string _password;
    string _player_role;

    ifstream readFile(filepath);

    // Checking if files not opened!
    if(!readFile.is_open()){
        cout << "File Cannot Be Opened!" << endl;
    }

    string each_line;

    // Iterating line by line through given filename/filepath
    while(getline(readFile, each_line)) {


        // Search for any whitespaces between strings/char
        auto str_iterator = each_line.find(' ');

        if (str_iterator != string::npos) {
            // Iterating through each line in the file
            _username = each_line.substr(str_iterator + 1, string::npos); // Username Line Found Here
            _password = each_line.substr(str_iterator + 1, string::npos);
            _player_role = each_line.substr(str_iterator+1, string::npos);
        }

        // Checking players username and password
        if(logging_ing_player.player_username() == _username){
            cout << _username << endl;
        }
        if(logging_ing_player.player_password() == _password){
            cout << _password << endl;
        }
        if(logging_ing_player.role_to_string(logging_ing_player) == _player_role){
            cout << _player_role << endl;
        }

        if (each_line.empty()){ printf("Player does not exist!"); break; }
    }

    */
}

string Login::set_filepath(string &username) {
    filepath = "/Users/aaronher/C++_Folder/Projects/Final_(Game_Programming)_Remastered_2/Player_Accounts/" + username;
    return filepath;
}

string Login::_filepath() {
    return filepath;
}