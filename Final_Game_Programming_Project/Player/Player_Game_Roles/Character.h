#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_CHARACTER_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_CHARACTER_H
#include <iostream>
#include <string>
#include <cstdlib>

#include "Game_Character.h"
#include "Warrior/Warrior.h"
#include "Hunter/Hunter.h"
using namespace std;

/*
 * - This class helps with transitioning game character into the following role
 * - Transitioning to:
 * Warrior
 * Hunter
 * Orc
 * Shaman
 * Wizard
 * - To also giving the character of that player the attributes belonging
 *  to each of these following role types
 *
 *
 * */

class Character : public Game_Character{
public:
    Character();
    explicit Character(Game_Character& _character);
    ~Character();

public:



private:
    Game_Character character;
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_CHARACTER_H
