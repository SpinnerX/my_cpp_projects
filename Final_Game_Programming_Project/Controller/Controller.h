#ifndef FINAL__GAME_PROGRAMMING__REMASTERED_2_CONTROLLER_H
#define FINAL__GAME_PROGRAMMING__REMASTERED_2_CONTROLLER_H
#include <iostream>
#include <iomanip>
#include <vector>

#include "../Viewer/Viewer.h"
#include "../Model/Model.h"
using namespace std;

class Controller {
public:
    Controller();
    ~Controller();

    void start_game();
private:
    void play(); // play game selected
    void player_login();
    void player_newAccount();

private:
    void game_mode(int i); // Game Mode Selection (Multiplayer/Singleplayer)

    void single_player();
    void multiplayer();

private:
    /*
     * Memory management here
    */
    void free_model(Model*);
    void free_viewer(Viewer*);

private:
    /*
     * - Declare variables
    */
    Model* player_model;
    Viewer* menu_viewer;
    Login logsIn;

    Player login_player;

    // Help assist when storing players
    vector<Player> player_vector;
};


#endif //FINAL__GAME_PROGRAMMING__REMASTERED_2_CONTROLLER_H
