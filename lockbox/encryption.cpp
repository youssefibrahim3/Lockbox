#include "encryption.h"

Encryption::Encryption() {}

void Encryption::generateSalt() {
    randombytes_buf(salt, sizeof(salt));
}

bool Encryption::deriveKey(QString pass) {
    QByteArray password = pass.toUtf8(); //converting to utf-8, then converting to const char* using constData()

    if (crypto_pwhash(pwKey, sizeof(pwKey), password.constData(), password.size(), salt, crypto_pwhash_OPSLIMIT_INTERACTIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE,crypto_pwhash_ALG_DEFAULT) != 0) {
        return false;
    }

    return true;
}

QByteArray Encryption::encrypt(QByteArray plaintext) {
    unsigned char encryptedMessage[crypto_secretbox_MACBYTES + plaintext.size()];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof(nonce));

    if (crypto_secretbox_easy(encryptedMessage, plaintext.constData(), plaintext.size(), nonce, pwKey) != 0) {

    }
}

QByteArray Encryption::decrypt(QByteArray ciphertext) {

}