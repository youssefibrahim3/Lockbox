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

bool Vault::save(const QString& filepath) {
    QJsonArray json_arr;
    for (const Account& account : accounts) {
        QJsonObject json_obj;
        json_obj["service"] = account.getService();
        json_obj["username"] = account.getUsername();
        json_obj["password"] = account.getPassword();
        json_obj["notes"] = account.getNotes();
        json_arr.append(json_obj);
    }

    QJsonObject vault_obj;
    vault_obj["vault"] = json_arr;

    QJsonDocument doc(vault_obj);

    QString json_string = doc.toJson();

    QFile save_file(filepath);
    if (!save_file.open(QIODevice::WriteOnly)) {
        return false;
    }

    save_file.write(json_string.toLocal8Bit());
    save_file.close();
    return true;
}

bool Vault::load(const QString& filepath) {
    return true;
}