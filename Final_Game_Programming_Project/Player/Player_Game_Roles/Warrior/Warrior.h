#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_WARRIOR_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_WARRIOR_H
#include <iostream>
#include <string>
#include <cstdint>

#include "../Game_Character.h"
using namespace std;

struct WarriorDamage{
    int damage;
    int critical_damage;
};

class Warrior : public Game_Character{
public:
    Warrior(); // Default
    explicit Warrior(Game_Character& player);

    int attack() override;
    int health_reduction() override;
    int armorHitpoints() override;
private:
    Game_Character character;
};

#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_WARRIOR_H
