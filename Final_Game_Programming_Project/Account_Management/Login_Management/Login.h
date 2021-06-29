#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_LOGIN_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_LOGIN_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "../../Player/Player.h"
using namespace std;

class Login {
public:
    Login();
    Login(string& username, string& password);

    bool login_check();

    void players_info();

public:
    string _filepath();
    string set_filepath(string& username);

private:

    Player logging_ing_player;
    string filepath;
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_LOGIN_H
