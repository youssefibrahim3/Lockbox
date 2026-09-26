#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <sodium.h>
#include <QString>

class Encryption
{
public:
    Encryption();

    bool deriveKey(QString pass);

    bool encrypt(QString pass);
    QString decrypt(QString encrypted);
private:
    unsigned char pwKey[crypto_secretbox_KEYBYTES];
};

#endif // ENCRYPTION_H
