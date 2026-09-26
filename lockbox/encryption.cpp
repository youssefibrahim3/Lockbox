#include "encryption.h"

Encryption::Encryption() {}

bool Encryption::deriveKey(QString pass) {
    unsigned char salt[crypto_pwhash_SALTBYTES];

    QByteArray password = pass.toUtf8(); //converting to utf-8, then converting to const char* using constData()

    randombytes_buf(salt, sizeof(salt));

    if (crypto_pwhash(pwKey, sizeof(pwKey), password.constData(), password.size(), salt, crypto_pwhash_OPSLIMIT_INTERACTIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE,crypto_pwhash_ALG_DEFAULT) != 0) {
        return false;
    }

    return true;
}

bool Encryption::encrypt(QString pass) {
    return true;
}

QString Encryption::decrypt(QString encrypted) {

}