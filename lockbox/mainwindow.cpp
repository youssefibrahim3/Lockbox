#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStandardPaths>

MainWindow::MainWindow(Vault& vault, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vault(vault)
{
    ui->setupUi(this);

    //Setting up filepath
    //QString filepath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/vault.json";
    QString testing_filepath = "vault.json";

    //Vault setup and data load
    vault = Vault();
    vault.load(testing_filepath);

    //Add to account list
    for (const Account& account : vault.getAccounts()) {
        ui->accountList->addItem(account.getService());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountList_currentRowChanged(int rowIndex)
{
    if (rowIndex < 0 || rowIndex >= vault.getNumberOfAccounts()) {
        activeAccountIndex = -1;
        return;
    }

    qDebug() << "rowIndex:" << rowIndex;
    qDebug() << "vault size" << vault.getNumberOfAccounts();

    activeAccountIndex = rowIndex;

    //populate UI with info
    Account& focusedAccount = vault.getAccount(activeAccountIndex);
    ui->usernameEdit->setText(focusedAccount.getUsername());
    ui->passwordEdit->setText(focusedAccount.getPassword());
    ui->notesEdit->setPlainText(focusedAccount.getNotes());
}


void MainWindow::on_addAccountButton_clicked()
{
    //Insert new empty account
    vault.addAccount("", "", ui->serviceNameEdit->text(), "");
    ui->accountList->addItem(ui->serviceNameEdit->text());
}


void MainWindow::on_showPassButton_clicked()
{
    if (ui->passwordEdit->echoMode() == QLineEdit::Password) {
        ui->showPassButton->setText("Hide");
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->showPassButton->setText("Show");
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_saveButton_clicked()
{
    if (activeAccountIndex == -1) return; // -1 means no account is currently selected
    Account& focusedAccount = vault.getAccount(activeAccountIndex);
    focusedAccount.setUsername(ui->usernameEdit->text());
    focusedAccount.setPassword(ui->passwordEdit->text());
    focusedAccount.setNotes(ui->notesEdit->toPlainText());
}


void MainWindow::on_deleteAccButton_clicked()
{
    if (activeAccountIndex == -1) return;
    ui->accountList->takeItem(activeAccountIndex);
    vault.removeAccount(activeAccountIndex);

    activeAccountIndex = -1;
}

void MainWindow::on_copyPasswordButton_clicked()
{
    if (activeAccountIndex == -1) return;
    ui->passwordEdit->copy();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    vault.save("vault.json");
    event->accept();
}
