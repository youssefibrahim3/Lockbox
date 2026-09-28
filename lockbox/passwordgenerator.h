#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>

class PasswordGenerator
{
public:
    PasswordGenerator();
    static QString generatePassword(int length);
};

#endif // PASSWORDGENERATOR_H
