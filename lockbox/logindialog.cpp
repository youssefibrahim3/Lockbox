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
    if (ui->passwordEdit->text() == vault.getMasterPass()) {
        QDialog::accept();
    }
}

