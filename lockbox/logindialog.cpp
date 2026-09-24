#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(Vault& vault, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , vault(vault)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    QString pass = "ASD"; //Temporary for testing
    if (ui->passwordEdit->text() == pass) {
        QDialog::accept();
    }
}

