#include "Model.h"
#include "Game_Modes/Singleplayer/Singleplayer.h"
#include "Game_Modes/Multiplayer/Multiplayer.h"
#include <fstream>
using namespace std;

Model::Model(){

}

Model::~Model() {
    delete this;
}

Login Model::player_login(Player& player_login){
    Player player = player_login;

    string username = player.player_username();
    string password = player.player_password();
    return Login(username, password);
}

void Model::new_player_account(string& username, string& password, int i) {
    player = Player(username, password, i);

    New_Account create_account = New_Account(player);
    create_account.newFile(player);
}

void Model::display_users_information(Login& login) {
    logAccount = login;

    string each_line;

    ifstream readFile(logAccount._filepath());

    while(getline(readFile, each_line)){
        cout << each_line << endl;
    }

}