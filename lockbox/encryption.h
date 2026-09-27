#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <sodium.h>
#include <QString>

class Encryption
{
public:
    Encryption();

    bool deriveKey(QString pass);

    QByteArray encrypt(QByteArray plaintext);
    QByteArray decrypt(QByteArray ciphertext);
private:
    unsigned char pwKey[crypto_secretbox_KEYBYTES];
    unsigned char salt[crypto_pwhash_SALTBYTES];
};

#endif // ENCRYPTION_H
