#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vault = Vault();
    vault.addAccount("GoogleAccount123","TheGoogleAccount","Google");
    vault.addAccount("GithubAccount123","TheGithubAccount","Github");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountList_currentRowChanged(int rowIndex)
{
    qDebug() << "rowIndex:" << rowIndex;
    qDebug() << "vault size" << vault.getNumberOfAccounts();

    activeAccountIndex = rowIndex;

    //populate UI with info
    Account& focusedAccount = vault.getAccount(activeAccountIndex);
    ui->usernameEdit->setText(focusedAccount.getUsername());
    ui->passwordEdit->setText(focusedAccount.getPassword());
}


void MainWindow::on_addAccountButton_clicked()
{
    //Insert new empty account

    vault.addAccount("", "", ui->serviceNameEdit->text());
    ui->accountList->addItem(ui->serviceNameEdit->text());
}


void MainWindow::on_showPassButton_clicked()
{
    if (ui->passwordEdit->echoMode() == QLineEdit::Password) {
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_saveButton_clicked()
{
    Account& focusedAccount = vault.getAccount(activeAccountIndex);
    focusedAccount.setUsername(ui->usernameEdit->text());
    focusedAccount.setPassword(ui->passwordEdit->text());
}

