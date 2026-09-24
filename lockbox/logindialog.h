#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "vault.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(Vault& vault, QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;
    Vault& vault;
};

#endif // LOGINDIALOG_H
