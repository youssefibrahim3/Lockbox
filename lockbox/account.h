#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
public:
    //Constructors
    Account();
    Account(QString username, QString password, QString service) : username(username), password(password), service(service) {}

    //Getters/Setters
    QString getPassword()const { return password; }
    QString getUsername()const { return username; }
    QString getService()const { return service; }

    void setPassword(QString pass) { password = pass; }
    void setUsername(QString user) { username = user; }
    void setService(QString serv) { service = serv; }
private:
    QString password;
    QString username;
    QString service;
};

#endif // ACCOUNT_H
