#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_GAME_CHARACTER_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_GAME_CHARACTER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <sstream>

#include <vector>

#include "../Player.h"
using namespace std;

/*
 * - Game_Character() is a base class
 * - Is derived from the
 *
*/

// Forward declarations
class Player;
class Login;

struct Player_Abilities{
    const char* ability_name;
    int dmg;
    int passive;
    int critical_dmg;
};

class Game_Character {
public:
    Game_Character();

    explicit Game_Character(Player &player);

    ~Game_Character();
public:
    Player _player();

    virtual string players_status();
    Player_Role role_isValid();

protected:
    virtual int attack();
    virtual int health_reduction();
    virtual int armorHitpoints();

private:
    Player player;

private:
    string username;
    string password;

protected:
    int health;
    int mana;
    int armor;

    int critical_dmg;
    int dmg;

    vector<Player_Abilities> store_abilities;
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_GAME_CHARACTER_H
