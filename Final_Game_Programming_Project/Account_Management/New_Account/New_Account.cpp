#include "New_Account.h"
#include <ostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <sys/stat.h>

#include "../../Player/Player.h"
using namespace std;

New_Account::New_Account() {
    filepath = "/Users/aaronher/C++_Folder/Projects/Final_(Game_Programming)_Remastered_2/Player_Accounts/";
    directory = mkdir(filepath.c_str(), 0777); // Creating a directory with the given filepath already created
}

New_Account::New_Account(Player &player) {
    filepath = "/Users/aaronher/C++_Folder/Projects/Final_(Game_Programming)_Remastered_2/Player_Accounts/" + player.player_username();
}

// protected member function
string New_Account::_filepath() {
    return filepath;
}

void New_Account::newFile(Player &newPlayer) {
    Player &player = newPlayer;

    ofstream newFile(filepath);

    vector<string> player_information = {player.player_username(), player.player_password(), player.role_to_string(player)};
    string arr[] = {"Username: ", "Password: ", "Player Role: "};

    // Iterating and saving information
    int i = 0;
    for (string &information : player_information) {
        newFile << arr[i++] << information << endl;
    }

    printf("New Player Has Been Created!\n");
    newFile.close();
}

/* [IN PROGRESS, FOR newDirectory() ]
 TODO:
 * - Implement directory, to open directory, and append new file in new directory
 * - Being able to save information after new creating directory/file
 * - Implement a file system, to being able to create multiple directories and files system.
*/
void New_Account::newDirectory(Player &newPlayer) {
    Player &player = newPlayer;

    string newDir = to_string(directory);
    ofstream newDirectory(newDir);

    newFile_2(newDir, newPlayer);

    if(!newDirectory){ cout << "Folder cannot be created!"; }

    newDirectory.close();

}

/*[IN PROGRESS]
 * - THis is helper function
 * - Supposed to help create new file in the new directory created
 * - Assist in checking if file already exists, or not
 * */
void New_Account::newFile_2(string& _directory, Player &newPlayer) {
    Player &player = newPlayer;

    string newFilePath = _directory + newPlayer.player_username();

    ofstream newFile(newFilePath);

    vector<string> player_information = {player.player_username(), player.player_password(), player.role_to_string(player)};
    string arr[] = {"Username: ", "Password: ", "Player Role: "};

    // Iterating and saving information
    int i = 0;
    for (string &information : player_information) {
        newFile << arr[i++] << information << endl;
    }

    printf("New Player Has Been Created!\n");
    newFile.close();
}

bool New_Account::readFile(Player& players) {
    string username;
    string password;

    ifstream readFile(filepath);

    // Checking if files not opened!
    if(!readFile.is_open()){
        cout << "File Cannot Be Opened!" << endl;
        return false;
    }

    string each_line;

    // Iterating line by line through given filename/filepath
    while(getline(readFile, each_line)) {


        // Search for any whitespaces between strings/char
        auto str_iterator = each_line.find(' ');

        if (str_iterator != string::npos) {
            // Iterating through each line in the file
            username = each_line.substr(str_iterator + 1, string::npos); // Username Line Found Here
            password = each_line.substr(str_iterator + 1, string::npos);
        }

        // Checking players username and password
        if(players.player_username() == username){
            continue;
        }
        if(players.player_password() == password){
            return true;
        }

        if (each_line.empty()){ printf("Player does not exist!"); break; }
    }
    return false;
}

bool New_Account::validation(Player& players) {
    string username;
    string password;

    ifstream readFile(filepath);

    // Checking if files not opened!
    if(!readFile.is_open()){
        cout << "File Cannot Be Opened!" << endl;
        return false;
    }

    string each_line;

    // Iterating line by line through given filename/filepath
    while(getline(readFile, each_line)) {


        // Search for any whitespaces between strings/char
        auto str_iterator = each_line.find(' ');

        if (str_iterator != string::npos) {
            // Iterating through each line in the file
            username = each_line.substr(str_iterator + 1, string::npos); // Username Line Found Here
            password = each_line.substr(str_iterator + 1, string::npos);
        }

        // Checking players username and password
        if(players.player_username() == username){
            continue;
        }
        if(players.player_password() == password){
            return true;
        }

        if (each_line.empty()){ printf("Player does not exist!"); break; }
    }
    return false;
}
