#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog l;

    if (l.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
    }
    return QApplication::exec();
}
