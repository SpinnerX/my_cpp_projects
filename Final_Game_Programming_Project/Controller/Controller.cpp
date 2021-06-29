#include "Controller.h"
using namespace std;

Controller::Controller() : player_model(new Model()), menu_viewer(new Viewer()){ }

Controller::~Controller() {
    // To free memory
    free(player_model);
    free(menu_viewer);
}

void Controller::start_game() {
    int i;

    while(true){
        menu_viewer->start_menu();
        cin >> i;

        if(i == 1)
            play();

        if(i < 1 || i > 1){
            printf("Leave Game Menu\n");
            // Freeing memory space (If needed!)
            break;
        }
    }
}

void Controller::player_login() {
    string username_input;
    string password_input;

    cout << "Enter username: ";
    cin >> username_input;

    cout << "Enter password: ";
    cin >> password_input;

    login_player = Player(username_input, password_input);

    string username = login_player.player_username();
    string password = login_player.player_password();

    logsIn = Login(username, password);

    if(logsIn.login_check()){
        cout << "Login SuccessFul" << endl;
        menu_viewer->game_mode_selectionMenu();
        int i;
        cin >> i;
        game_mode(i);
    }
    else{
        // cout << "Login Failed!" << endl;
        return;
    }
}

void Controller::player_newAccount() {
    cout << "Enter New Username: ";
    string newUsername;
    cin >> newUsername;

    cout << "Enter New Password: ";
    string newPassword;
    cin >> newPassword;

    menu_viewer->role_selection();
    int role_select;
    cin >> role_select;

    player_model->new_player_account(newUsername, newPassword, role_select);

}

void Controller::game_mode(int i) {
    switch (i) {
        case 1:
            single_player();
            break;
        case 2:
            multiplayer();
            break;
        default:
            cout << "Default" << endl;
            break;
    }
}

void Controller::single_player() {
    cout << "Single Player Start!" << endl;
    player_model->display_users_information(logsIn);
}

void Controller::multiplayer() {
    cout << "Multiplayer Start!" << endl;
    player_model->display_users_information(logsIn);
}

void Controller::free_model(Model * model) {
    free(model);
}

void Controller::free_viewer(Viewer * viewer) {
    free(viewer);
}

void Controller::play() {
    int login_input;
    while(true) {
        menu_viewer->playerGame_LoginMenu();
        cin >> login_input;

        if(login_input == 1)
            player_login();
        if(login_input == 2)
            player_newAccount();
        if(login_input < 1 || login_input > 2) break;
    }
}