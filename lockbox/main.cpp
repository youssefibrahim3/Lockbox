#include "mainwindow.h"
#include "logindialog.h"
#include "createpassdialog.h"
#include "vault.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Vault vault;
    vault.load("vault.json");

    if (vault.getMasterPass().isEmpty()) { //No master password set, have to make a new one
        CreatePassDialog c;

        if (c.exec() == QDialog::Accepted) {
            vault.setMasterPass(c.getPassword());
            vault.save("vault.json");
        } else {
            return 0;
        }
    }

    LoginDialog l(vault);

    if (l.exec() == QDialog::Accepted) {
        MainWindow w(vault);
        w.show();
        return a.exec();
    }

    return 0;
}
