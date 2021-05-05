#ifndef LOGIN_SYSTEM_LOGIN_WINDOW_H
#define LOGIN_SYSTEM_LOGIN_WINDOW_H
#pragma once
#include "Accounts/Register/Register_Account.h"
#include "Accounts/Account.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QDir>
#include <QKeyEvent>
#include <QIcon>
#include <iostream>
using namespace std;

class Login_Window : public QMainWindow {
private:
    // Implementing positioning variables for
    int width;
    int height;
    int xpos;
    int ypos;

    // Implementing widgets
    QPushButton *login_button;
    QPushButton *cancel_button;
    QPushButton *register_button;
    QLineEdit *set_username;
    QLineEdit *set_password;
    QWidget *background_image;
    QString file_path;
private:
    Account *account;
    Register_Account *register_account;
protected:
    QString get_password();
    QString get_username();
private:
    // Creating account & users accounts here

private:
    // Login Action/Processing
    void login_widgets(); // Handling login widgets to login window
    void logged_account(); // logging into account

private slots:
    // Processing usernames and passwords
    bool processing_username(const QString&);
    bool processing_password(const QString&);
    QString encrypting_information(QString&);

    // Executed when either buttons clicked
    void login_clicked();
    void cancel_clicked();
    void register_clicked();
    // void enterKey_Event(QKeyEvent *Event); // handling when <enter> key is pressed
public:
    // explicit Login_Window();
    explicit Login_Window(QWidget *root=nullptr);
};

#endif //LOGIN_SYSTEM_LOGIN_WINDOW_H
