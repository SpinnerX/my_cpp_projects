#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_VIEWER_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_VIEWER_H
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Viewer {
public:
    Viewer();
    ~Viewer();

    void start_menu();
    void playerGame_LoginMenu();

    void login_menu();
    void player_gameMenu(); // Start Menu After Logging in
    void role_selection(); // Role selection, for when player want's to create new character
    void game_mode_selectionMenu();
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_VIEWER_H
