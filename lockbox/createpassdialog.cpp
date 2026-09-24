#include "createpassdialog.h"
#include "ui_createpassdialog.h"

CreatePassDialog::CreatePassDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreatePassDialog)
{
    ui->setupUi(this);
}

CreatePassDialog::~CreatePassDialog()
{
    delete ui;
}

void CreatePassDialog::on_loginButton_clicked()
{
    if (ui->passwordEdit->text() == ui->confirmPasswordEdit->text() && ui->passwordEdit->text().length() >= 10) {
        password = ui->passwordEdit->text();
        QDialog::accept();
    }
}

QString CreatePassDialog::getPassword()const {
    return password;
}


void CreatePassDialog::on_showPassButton_clicked()
{
    if (ui->passwordEdit->echoMode() == QLineEdit::Password) {
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
    }
}


void CreatePassDialog::on_showConfirmPassButton_clicked()
{
    if (ui->confirmPasswordEdit->echoMode() == QLineEdit::Password) {
        ui->confirmPasswordEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    }
}

