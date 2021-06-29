#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_NEW_ACCOUNT_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_NEW_ACCOUNT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
using namespace std;

// Forward Declarations
class Player;

class New_Account {
public:
    New_Account(); // Default
    explicit New_Account(Player& player);

    // - Creating new files, opens and appends information into file based on username
    // - Reading text line by line in file
    // - Creating new directory, that holds players status, player info, and etc...
    // Validation() helper validates if username and password already exists!
    void newFile(Player& newPlayer);
    void newDirectory(Player& newPlayer);
    bool readFile(Player&);

    bool validation(Player& players);
protected:
    void newFile_2(string& _directory, Player &newPlayer);
protected:
    string _filepath();

private:
    std::string filepath;
    int directory;
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_NEW_ACCOUNT_H
