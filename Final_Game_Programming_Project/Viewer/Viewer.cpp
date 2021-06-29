#include "Viewer.h"
using namespace std;

Viewer::Viewer() = default;

Viewer::~Viewer() {
    delete this;
}

void Viewer::start_menu() {
    cout << "================[MAIN MENU]=================" << endl
         << "1. Play Game" << endl
         << "0. Leave Menu Selection" << endl
         << "============================================" << endl
         << "Enter Option Number: ";
}

void Viewer::playerGame_LoginMenu() {
    cout << "================[LOGIN SELECTION]=================" << endl
         << "1. Login" << endl
         << "2. Create Account" << endl
         << "0. Leave Login Menu" << endl
         << "=================================================" << endl
         << "Select an Option: ";
}

void Viewer::login_menu() {
    cout << "1. Login" << endl
         << "2. Create Account" << endl
         << "0. Leave Login Selection" << endl
         << "Select an option: ";
}

void Viewer::player_gameMenu() {
    cout << "1. Play Game" << endl
         << "2. Create Character" << endl
         << "0. Leave Game Selection" << endl
         << "Select an option: ";
}


void Viewer::game_mode_selectionMenu() {
    cout << "================[GAME MODE]=================" << endl
         << "1. Single Player" << endl
         << "2. Multiplayer" << endl
         << "0. Leave Selection" << endl
         << "=================================================" << endl
         << "Enter Option: ";
}

void Viewer::role_selection() {
    cout << "1. Warrior" << endl
         << "2. Hunter" << endl
         << "3. Orc" << endl
         << "4. Shaman" << endl
         << "5. Wizard" << endl
         << "Select Role: ";
}