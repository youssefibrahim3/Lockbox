#include "vault.h"

Vault::Vault() {}

void Vault::addAccount(Account account) {
    accounts.push_back(account);
}

void Vault::addAccount(QString username, QString password, QString service) {
    Account newAccount = Account(username, password, service);
    accounts.push_back(newAccount);
}

void Vault::removeAccount(int index) {
    accounts.erase(accounts.begin() + index);
}

Account& Vault::getAccount(int index) {
    return accounts.at(index);
}

int Vault::getNumberOfAccounts()const {
    return accounts.size();
}
