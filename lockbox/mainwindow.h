#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QClipboard>
#include "vault.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Vault& vault, QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_accountList_currentRowChanged(int currentRow);

    void on_addAccountButton_clicked();

    void on_showPassButton_clicked();

    void on_saveButton_clicked();

    void on_deleteAccButton_clicked();

    void on_copyPasswordButton_clicked();

    void closeEvent(QCloseEvent *event) override;
private:
    Ui::MainWindow *ui;
    Vault& vault;
    int activeAccountIndex;
};
#endif // MAINWINDOW_H
