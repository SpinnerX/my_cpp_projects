#include "Register_Account.h"
#include "../../Login_Window.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
using namespace std;

/*Register_Account::Register_Account() {
    //set_username = "";
    // set_password = "";
    register_username = nullptr;
    register_password = nullptr;
    login_information = "";
    register_button = nullptr;
    back_button = nullptr;
    error_message = nullptr;
    width = 0;
    height = 0;
    xpos = 0;
    ypos = 0;
}*/

Register_Account::Register_Account(QWidget *root) : QWidget(root){
    // Implementing width & height
    width = 200;
    height = 30;

    // Implementing positions by x & y
    xpos = 1100;
    ypos = 500;

    register_username = new QLineEdit(this);
    register_username->setPlaceholderText("new username");
    register_username->move(QPoint(xpos, ypos));
    register_username->resize(width, height);
    register_username->setFocus();

    ypos = 550;
    register_password = new QLineEdit(this);
    register_password->setPlaceholderText("new password");
    register_password->move(QPoint(xpos, ypos));
    register_password->resize(width, height);
    register_password->setEchoMode(QLineEdit::Password);
    register_password->setFocus();

    // Setting buttons width & height
    //Setting position for y
    width = 95;
    height = 50;
    ypos = 600;
    register_button = new QPushButton("Register", this);
    register_button->resize(width, height);
    register_button->move(QPoint(xpos, ypos));

    xpos = 1200;
    ypos = 600;
    back_button = new QPushButton("Go Back", this);
    back_button->resize(width, height);
    back_button->move(QPoint(xpos, ypos));
    back_button->setFocus();

    connect(register_button, &QPushButton::released, this, &Register_Account::register_clicked);
    connect(back_button, &QPushButton::released, this, &Register_Account::back_clicked);


    setWindowTitle("Register Account");
}

QString Register_Account::get_username() {
    // username = register_username->text();
    return register_username->text();
}

QString Register_Account::get_password() {
    password = register_password->text();
    return password;
}

QString Register_Account::process_information() {
    login_information = "Username: " + get_username() + "\nPassword: " + get_password();
    return login_information;
}

void Register_Account::save(QString &username) {
    filepath = ("/Users/aaronher/CLionProjects/Github_Projects/Login_System/Users/" + username);
    QFile check_file(filepath);

    if (!check_file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream get_stream(&check_file);
    get_stream << process_information();

    // returning to main window
    back_clicked();
}

void Register_Account::register_clicked() {

    if (register_username->text() == "" && register_password->text() == ""){
        // width = 500;
        // height = 200;
        // error_message = new QMessageBox(this);
        // error_message->warning(this, "Error Processing", "There were no inputs processed");
        // error_message->setFixedSize(width, height);
    }
    else {
        username = get_username();
        save(username);
    }
}

void Register_Account::back_clicked() {
    Login_Window *root_window = new Login_Window(this);
    root_window->showMaximized();
    this->hide();
}