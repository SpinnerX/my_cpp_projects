#include "Player.h"
using namespace std;

Player::Player() {
    username = "";
    password = "";
    role = Default;
}

Player::Player(string &_username, string &_password) : username(_username), password(_password){ }

Player::Player(string &_username, string &_password, int role_input) : username(_username), password(_password){
    role = setRole(role_input);
}

Player_Role Player::getRole() {
    return role;
}

int Player::_role() const {
    return role;
}

Player_Role Player::setRole(int role_input) {
    switch (role_input){
        case Warrior:
            return Warrior;
        case Hunter:
            return Hunter;
        case Orc:
            return Orc;
        case Shaman:
            return Shaman;
        case Wizard:
            return Wizard;
        default:
            return Default;
    }
}

string Player::role_to_string(Player& role) {
    string role_label;

    Player_Role selected_role = role.getRole();

    if (selected_role == Warrior){
        return "Warrior";
    }
    else if (selected_role == Hunter){
        return "Hunter";
    }
    else if(selected_role == Orc){
        return "Orc";
    }
    else if (selected_role == Shaman){
        return "Shaman";
    }
    else if(selected_role == Wizard){
        return "Wizard";
    }
    else {
        return "N/A";
    }
}

string Player::player_username() {
    return username;
}

string Player::player_password() {
    return password;
}