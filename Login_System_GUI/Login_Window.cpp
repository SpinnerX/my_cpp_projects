#include "Login_Window.h"
#include <QFile>
#include <QTextStream>
using namespace std;

Login_Window::Login_Window(QWidget *root) : QMainWindow(root){
    // layout of login window

    // background_image = new QWidget(this);

    // Assigning height & width
    width = 500;
    height = 450;

    // background_image->setStyleSheet(); // Not yet
    // background_image->move(QPoint(950, 30));
    // background_image->resize(width, height);

    // Add Login_Widgets() here
    login_widgets();

    setWindowTitle("Login Window");
}

void Login_Window::login_widgets() {
    // setting username textbox
    set_username = new QLineEdit(this);
    set_username->setPlaceholderText("enter username");

    // Assigning the x-position & y-position
    // For username text box
    width = 200;
    height = 30;
    xpos = 550; // Higher the number, xpos goes to the right
    ypos = 300; // lower the number higher the ypos to the top

    // Setting username & password inputs
    set_username->move(QPoint(xpos, ypos));
    set_username->resize(width, height);
    set_username->setFocus();

    // Assigning the x-position & y-position
    // for password text box
    width = 200;
    height = 30;
    xpos = 550; // Higher the number, xpos goes to the right
    ypos = 340; // lower the number higher the ypos to the top

    set_password = new QLineEdit(this);
    set_password->setPlaceholderText("enter password");
    set_password->move(QPoint(xpos, ypos));
    set_password->resize(width, height);
    set_password->setEchoMode(QLineEdit::Password);
    set_password->setFocus();

    // implementing login button
    width = 95;
    height = 50;
    // xpos = 1100;
    xpos = 550; // higher the number
    ypos = 400; // Lower the number higher the position

    login_button = new QPushButton("Login",this);
    login_button->resize(width, height);
    login_button->move(QPoint(xpos, ypos));
    login_button->setShortcut(Qt::EnterKeyReturn); // Setting shortcut for user to type <enter> key

    // implementing cancel button
    // Positioning cancel button
    // for cancel button
    width = 95;
    height = 50;
    xpos = 650;
    ypos = 400;

    cancel_button = new QPushButton("Cancel", this);
    cancel_button->resize(width, height);
    cancel_button->move(QPoint(xpos, ypos));
    cancel_button->setFocus();

    // Implementing registering account button
    // for register button
    width = 90;
    height = 50;
    xpos = 550;
    ypos = 450;

    register_button = new QPushButton("Register", this);
    register_button->resize(width, height);
    register_button->move(QPoint(xpos, ypos));

    // Connecting buttons widgets to the click events
    connect(login_button, &QPushButton::released, this, &Login_Window::login_clicked);
    connect(cancel_button, &QPushButton::released, this, &Login_Window::cancel_clicked);
    connect(register_button, &QPushButton::released, this, &Login_Window::register_clicked);
}

QString Login_Window::get_username() {
    QString username = set_username->text();
    return username;
}

QString Login_Window::get_password() {
    QString password = set_password->text();
    return password;
}



bool Login_Window::processing_username(const QString& username) {
    file_path = ("/Users/aaronher/CLionProjects/Github_Projects/Login_System/Users/" + username);
    QFile check_file(file_path);

    // Checking if username exists
    if (get_username() == check_file.exists()){
        if (processing_password(file_path)){
            return true;
        }
    }
    else{
        return false;
    }
    return false; // Default value
}

bool Login_Window::processing_password(const QString& path){
    QFile password_input(path);

    // Checking file if password exists!
    if (password_input.atEnd()){
        QTextStream check_pass(&password_input);

        while (!check_pass.atEnd()){
            QString read_line = check_pass.readLine();

            if (get_password().isSimpleText() == read_line){
                return true;
            } else
                return false;
        }
    }
    else{
        return false;
    }

    return false; // Default value
}

void Login_Window::cancel_clicked() {
    this->close();
    exit(0);
}
void Login_Window::login_clicked() {
    if (processing_username(set_username->text())){
        logged_account();
    }
    else{

    }
}

void Login_Window::register_clicked() {
    this->hide();
    register_account = new Register_Account;
    register_account->showMaximized();
}

void Login_Window::logged_account() {
    account = new Account;
    account->showMaximized();
    this->hide(); // hide main window here!
}