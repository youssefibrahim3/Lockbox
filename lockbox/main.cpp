#include "mainwindow.h"
#include "logindialog.h"
#include "createpassdialog.h"
#include "vault.h"
#include <QApplication>
#include <sodium.h>
#include <QFile>

int main(int argc, char *argv[])
{
    if (sodium_init() < 0) {
        qDebug() << "Libsodium failed to initialize, exiting program";
        return 0;
    }
    QApplication a(argc, argv);

    Vault vault;
    if (QFile::exists("vault.json")) {
        LoginDialog l(vault);
        if (l.exec() != QDialog::Accepted) {
            return 0;
        }

        QString masterPassword = l.getPassword();

        if (!vault.load("vault.json", masterPassword)) {
            return 0;
        }

    } else {
        CreatePassDialog c;
        if (c.exec() != QDialog::Accepted) {
            return 0;
        }

        QString masterPassword = c.getPassword();
        vault.initializeSalt(masterPassword);

        if(!vault.save("vault.json")) {
            qDebug() << "Failed to save vault";
            return 0;
        }
    }

    MainWindow w(vault);
    w.show();

    return a.exec();
}
