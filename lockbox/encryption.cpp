#include "encryption.h"

Encryption::Encryption() {}

void Encryption::generateSalt() {
    randombytes_buf(salt, sizeof(salt));
}

void Encryption::setSalt(const QByteArray& salt) {
    memcpy(this->salt, salt.constData(), crypto_pwhash_SALTBYTES);
}

bool Encryption::deriveKey(QString pass) {
    QByteArray password = pass.toUtf8(); //converting to utf-8, then converting to const char* using constData()

    if (crypto_pwhash(pwKey, sizeof(pwKey), password.constData(), password.size(), salt, crypto_pwhash_OPSLIMIT_INTERACTIVE, crypto_pwhash_MEMLIMIT_INTERACTIVE,crypto_pwhash_ALG_DEFAULT) != 0) {
        return false;
    }

    return true;
}

QByteArray Encryption::encrypt(QByteArray plaintext) { // returns [nonce][ciphertext]
    unsigned char encryptedMessage[crypto_secretbox_MACBYTES + plaintext.size()];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof(nonce));

    if (crypto_secretbox_easy(encryptedMessage, reinterpret_cast<const unsigned char*>(plaintext.constData()), plaintext.size(), nonce, pwKey) != 0) {
        return {};
    }

    //data is returned WITH the nonce to allow for decryption using decrypt()
    QByteArray result;
    result.append(
        reinterpret_cast<const char*>(nonce),
        crypto_secretbox_NONCEBYTES
        );
    result.append(
        reinterpret_cast<const char*>(encryptedMessage),
        crypto_secretbox_MACBYTES + plaintext.size()
        );
    return result;
}

QByteArray Encryption::decrypt(QByteArray ciphertext) {
    unsigned char decryptedMessage[crypto_secretbox_MACBYTES + ciphertext.size()];
    const unsigned char* nonce = reinterpret_cast<const unsigned char*>(ciphertext.constData());
    const unsigned char* encryptedMessage = reinterpret_cast<const unsigned char*>(ciphertext.constData()+crypto_secretbox_NONCEBYTES);

    if (crypto_secretbox_open_easy(decryptedMessage,encryptedMessage, ciphertext.size() - crypto_secretbox_NONCEBYTES, nonce, pwKey) != 0) {
        return {};
    }

    return QByteArray(reinterpret_cast<const char*>(decryptedMessage),
                      ciphertext.size() - crypto_secretbox_MACBYTES - crypto_secretbox_NONCEBYTES);
}