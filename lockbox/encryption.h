#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <sodium.h>
#include <QString>

class Encryption
{
public:
    Encryption();

    bool deriveKey(QString pass);
    void generateSalt();

    QByteArray encrypt(QByteArray plaintext);
    QByteArray decrypt(QByteArray ciphertext);

    QByteArray getSalt()const { return QByteArray(reinterpret_cast<const char*>(salt)); }
    void setSalt(const QByteArray& salt);
private:
    unsigned char pwKey[crypto_secretbox_KEYBYTES];
    unsigned char salt[crypto_pwhash_SALTBYTES];
};

#endif // ENCRYPTION_H
