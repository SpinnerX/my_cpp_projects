#include "Game_Character.h"

using namespace std;

Game_Character::Game_Character() {
    player = Player();
}

Game_Character::Game_Character(Player &player) {
    username = player.player_username();
    password = player.player_password();

    this->player = Player(username, password, player._role());

    health = 1;
    mana = 0;
    armor = 0;
    critical_dmg = 0;
    store_abilities = vector<Player_Abilities>();
}

Game_Character::~Game_Character(){ }

string Game_Character::players_status() {
    string status;
    status = "Health: " + to_string(health) + "\tMana: " + to_string(mana);

    return status;
}

Player Game_Character::_player() {
    return player;
}

Player_Role Game_Character::role_isValid() {
    switch (player.getRole()) {
        case Warrior: return Warrior;
        case Hunter: return Hunter;
        case Orc: return Orc;
        case Shaman: return Shaman;
        case Wizard: return Wizard;
        case Default: return Default;
    }
}

int Game_Character::attack() {
    return 0;
}

int Game_Character::health_reduction() {
    return 0;
}

int Game_Character::armorHitpoints() {
    return 0;
}

