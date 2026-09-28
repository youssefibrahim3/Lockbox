#include "passwordgenerator.h"

PasswordGenerator::PasswordGenerator() {}

QString PasswordGenerator::generatePassword(int length) {
    // Generates and returns password.
    const QString ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const QString alphabet = "abcdefghijklmnopqrstuvwxyz";
    const QString symbols = "!@#$%^&*()";
    const QString number = "0123456789";
    QString  password = "";
    int selection;
    int secondSelection;

    for (int i = 1; i <= length; i++) {
        //std::cout << i;
        selection = rand() % 4;
        switch (selection) {
        case 0: //cap alphabet
            secondSelection = rand() % (ALPHABET.length());
            password += ALPHABET[secondSelection];
            break;
        case 1: //low alphabet
            secondSelection = rand() % (alphabet.length());
            password += alphabet[secondSelection];
            break;
        case 2: //sym
            secondSelection = rand() % (symbols.length());
            password += symbols[secondSelection];
            break;
        case 3: //num
            secondSelection = rand() % (number.length());
            password += number[secondSelection];
            break;
        };
    }
    return password;
}