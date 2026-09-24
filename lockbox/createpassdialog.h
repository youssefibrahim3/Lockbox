#ifndef CREATEPASSDIALOG_H
#define CREATEPASSDIALOG_H

#include <QDialog>

namespace Ui {
class CreatePassDialog;
}

class CreatePassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePassDialog(QWidget *parent = nullptr);
    ~CreatePassDialog();

    QString getPassword()const;

private slots:
    void on_loginButton_clicked();

    void on_showPassButton_clicked();

    void on_showConfirmPassButton_clicked();

private:
    Ui::CreatePassDialog *ui;
    QString password;
};

#endif // CREATEPASSDIALOG_H
