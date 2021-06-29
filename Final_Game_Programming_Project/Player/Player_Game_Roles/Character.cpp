#include "Character.h"
using namespace std;

Character::Character() {
    character = Game_Character();
}

Character::Character(Game_Character& _character) {
    this->character = _character;
}

Character::~Character() { }



