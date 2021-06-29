#include "Warrior.h"
using namespace std;

Warrior::Warrior(){
}

Warrior::Warrior(Game_Character& player) {
    character = player;
}

int Warrior::attack() {
    WarriorDamage dmg;
    dmg.damage = rand() % 20;
    return dmg.damage;
}

int Warrior::armorHitpoints() {
    return 0;
}

int Warrior::health_reduction() {
    return 0;
}