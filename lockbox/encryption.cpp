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

    if (crypto_secretbox_easy(encryptedMessage, reinterpret_cast<const unsigned char*>(plaintext.constData()), plaintext.size(), nonce, pwKey) != 0) {

    }

    return QByteArray(reinterpret_cast<const char*>(encryptedMessage));
}

QByteArray Encryption::decrypt(QByteArray ciphertext) {
    unsigned char decryptedMessage[crypto_secretbox_MACBYTES + ciphertext.size()];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];

    if (crypto_secretbox_open_easy(decryptedMessage,reinterpret_cast<const unsigned char*>(ciphertext.constData()), ciphertext.size(), nonce, pwKey) != 0) {

    }
}