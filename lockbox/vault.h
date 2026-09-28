#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "account.h"
#include "encryption.h"

class Vault
{
public:
    Vault();
    void initializeSalt(QString masterPassword);

    std::vector<Account> getAccounts()const { return accounts; }
    void setAccounts(std::vector<Account> newAccounts) { accounts = newAccounts; }

    void addAccount(Account account);
    void addAccount(QString username, QString password, QString service, QString notes);

    void removeAccount(int index);

    Account& getAccount(int index);

    int getNumberOfAccounts()const;

    bool save(const QString& filepath);
    bool load(const QString& filepath, const QString& masterPass);
private:
    std::vector<Account> accounts;
    Encryption encryption;
};

#endif // VAULT_H
