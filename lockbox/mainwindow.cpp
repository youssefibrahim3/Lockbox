#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vault = Vault();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountList_currentRowChanged(int rowIndex)
{
    activeAccountIndex = rowIndex;

    //populate UI with info
}


void MainWindow::on_addAccountButton_clicked()
{
    //Insert new account, probably use a form to name it or something
}

