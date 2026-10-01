#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <mutex>


class BankAccount
{
public:
    BankAccount(const std::string& accountId);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    const std::string& getAccountId() const;
    

private:
    std::string accountId;
    double balance;
    double initialBalance;
    mutable std::mutex bankMutex;
};  


#endif