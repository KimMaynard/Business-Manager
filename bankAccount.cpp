#include "bankAccount.h"
#include <mutex>

BankAccount::BankAccount(const std::string& accountId)
    : accountId(accountId), balance(0.0)
{
}

bool BankAccount::withdraw(double amount){
    std::lock_guard<std::mutex> lock(bankMutex);
    if(amount > 0 && amount <= balance){
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

bool BankAccount::deposit(double amount){
    std::lock_guard<std::mutex> lock(bankMutex);
    if(amount > 0){
        balance += amount;
        return true;
    } else {
        return false;
    }
}

const std::string& BankAccount::getAccountId() const{
    return accountId;
}

double BankAccount::getBalance() const{
    std::lock_guard<std::mutex> lock(bankMutex);
    return balance;
}