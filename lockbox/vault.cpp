#include "vault.h"

Vault::Vault() {}

void Vault::addAccount(Account account) {
    accounts.push_back(account);
}

void Vault::addAccount(QString username, QString password, QString service, QString notes) {
    Account newAccount = Account(username, password, service, notes);
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
    QFile save_file(filepath);

    if (!save_file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray save_data = save_file.readAll();

    QJsonDocument load_doc(QJsonDocument::fromJson(save_data));

    QJsonObject loaded_obj = load_doc.object();

    save_file.close();

    //now read off of it and populate

    accounts.clear();

    const QJsonArray loaded_arr = loaded_obj["vault"].toArray();
    for (const QJsonValue &account : loaded_arr) {
        QJsonObject account_obj = account.toObject();
        addAccount(account_obj["username"].toString(),
                   account_obj["password"].toString(),
                   account_obj["service"].toString(),
                   account["notes"].toString());
    }

    return true;
}