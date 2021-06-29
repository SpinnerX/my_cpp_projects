cmake_minimum_required(VERSION 3.19)
project(Final_Game_Programming_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Final_Game_Programming_Project
        main.cpp
        Viewer/Viewer.h
        Viewer/Viewer.cpp
        Controller/Controller.h
        Controller/Controller.cpp
        Model/Model.h
        Model/Model.cpp
        Model/Game_Modes/Singleplayer/Singleplayer.h
        Model/Game_Modes/Singleplayer/Singleplayer.cpp
        Model/Game_Modes/Multiplayer/Multiplayer.h
        Model/Game_Modes/Multiplayer/Multiplayer.cpp
        Account_Management/New_Account/New_Account.h
        Account_Management/New_Account/New_Account.cpp
        Account_Management/Login_Management/Login.h
        Account_Management/Login_Management/Login.cpp
        Player/Player.h
        Player/Player.cpp
        Player/Player_Game_Roles/Game_Character.h
        Player/Player_Game_Roles/Game_Character.cpp
        Player/Player_Game_Roles/Character.h
        Player/Player_Game_Roles/Character.cpp
        Player/Player_Game_Roles/Warrior/Warrior.h
        Player/Player_Game_Roles/Warrior/Warrior.cpp
        Player/Player_Game_Roles/Hunter/Hunter.h
        Player/Player_Game_Roles/Hunter/Hunter.cpp
        Account_Management/My_FileSystem/Game_FileSystem.cpp Account_Management/My_FileSystem/Game_FileSystem.h)