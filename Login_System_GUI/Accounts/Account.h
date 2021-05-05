#ifndef LOGIN_SYSTEM_ACCOUNT_H
#define LOGIN_SYSTEM_ACCOUNT_H
#pragma once
#include "Account.h"
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QDir>
#include <QFrame>
#include <QIODevice>
#include <QTextStream>
#include <QPushButton>
using namespace std;

class Account : public QWidget{
private:
    // Implementing variables here
    QPushButton *testing_button;
private slots:
    void clicked();
public:
    explicit Account(QWidget *root=nullptr);

};


#endif //LOGIN_SYSTEM_ACCOUNT_H
