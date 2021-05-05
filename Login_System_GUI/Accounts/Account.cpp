#include "Account.h"
using namespace std;


Account::Account(QWidget *root) : QWidget(root) {
    testing_button = new QPushButton(this);
    testing_button->setText("Click Me!");

    connect(testing_button, &QPushButton::released, this, &Account::clicked);

    setWindowTitle("Account");
}

void Account::clicked() {
    this->close();
    exit(0);
}