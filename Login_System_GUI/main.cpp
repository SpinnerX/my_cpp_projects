#include <QApplication>
#include "Login_Window.h"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication root_app(argc, argv);

    Login_Window login;
    login.showMaximized();

    return QApplication::exec();
}
