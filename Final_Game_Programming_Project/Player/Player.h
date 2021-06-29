#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_PLAYER_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_PLAYER_H
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

enum Player_Role{
    Warrior = 1,
    Hunter = 2,
    Orc = 3,
    Shaman = 4,
    Wizard = 5,
    Default = 0
};

class Player {
public:
    Player();
    Player(string &_username, string &_password);
    Player(string &_username, string &_password, int);

    Player_Role getRole();
    int _role() const;
    Player_Role setRole(int);

    string role_to_string(Player& role);

public:
    string player_username();
    string player_password();

private:
    string username;
    string password;
    Player_Role role;
};

#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_PLAYER_H
