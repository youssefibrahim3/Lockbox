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
    QString getNotes()const { return notes; }

    void setPassword(QString pass) { password = pass; }
    void setUsername(QString user) { username = user; }
    void setService(QString serv) { service = serv; }
    void setNotes(QString note) { notes = note; }
private:
    QString password;
    QString username;
    QString service;
    QString notes;
};

#endif // ACCOUNT_H
