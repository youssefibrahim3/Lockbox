#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include "account.h"

class Vault
{
public:
    Vault();

    std::vector<Account> getAccounts()const { return accounts; }
    void setAccounts(std::vector<Account> newAccounts) { accounts = newAccounts; }

    void addAccount(Account account);
    void addAccount(QString username, QString password, QString service);

    void removeAccount(int index);

    Account& getAccount(int index);

    int getNumberOfAccounts()const;

    bool save(QString& filename);
    bool load(QString& filename);
private:
    std::vector<Account> accounts;
};

#endif // VAULT_H
