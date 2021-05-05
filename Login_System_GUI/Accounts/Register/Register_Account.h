#ifndef LOGIN_SYSTEM_REGISTER_ACCOUNT_H
#define LOGIN_SYSTEM_REGISTER_ACCOUNT_H
#pragma once
#include "Register_Account.h"
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QLineEdit>
#include <QLabel>
#include <QBoxLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
using namespace std;

class Register_Account : public QWidget{
private:
    int width;
    int height;
    int xpos, ypos;
    // QString set_username, set_password;
    QString login_information;
    QString filepath;
    QString username;
    QString password;
    QMessageBox *error_message;
    QLineEdit *register_username, *register_password;
    QPushButton *register_button;
    QPushButton *back_button;
protected:
    QString get_username();
    QString get_password();
    QString process_information();
private slots:
    void save(QString &); // Saving username & password
    void register_clicked();
    void back_clicked();
public:
    // explicit  Register_Account();
    explicit Register_Account(QWidget *root=nullptr);
};

#endif //LOGIN_SYSTEM_REGISTER_ACCOUNT_H