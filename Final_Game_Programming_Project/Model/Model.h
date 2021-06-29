#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_MODEL_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_MODEL_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdint>

#include "../Player/Player.h"
#include "../Account_Management/New_Account/New_Account.h"
#include "../Account_Management/Login_Management/Login.h"

// Declare player here
using namespace std;

// Forward Declarations
class Singleplayer;
class Multiplayer;

class Model {
public:
    Model();
    ~Model();
    Login player_login(Player& player_login);
    void new_player_account(string& username, string& password, int i);
public:
    // void singleplayer();
    // void multiplayer();

    void display_users_information(Login& login_information);
private:
    Player player;
    New_Account newAccount;
    Login logAccount;
};

#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_MODEL_H
