#include "mainwindow.h"
#include "logindialog.h"
#include "vault.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Vault vault;
    vault.load("vault.json");

    LoginDialog l;

    if (l.exec() == QDialog::Accepted) {
        MainWindow w(vault);
        w.show();
        return a.exec();
    }

    return 0;
}
