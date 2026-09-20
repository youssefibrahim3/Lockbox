#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include <QString>
#include "account.h"

class Vault
{
public:
    Vault();

private:
    std::vector<Account> accounts;
};

#endif // VAULT_H
