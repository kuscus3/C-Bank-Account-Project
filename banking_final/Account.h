#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
    int id;
    String name;
    int money;
public:
    Account(int _id, String _name, int _money);
    // Account(const Account& copyAcc);
    // Account & operator=(const Account & ref);
    int getId() const;
    int getMoney() const;
    virtual void moneyDeposit(double tempmoney);
    void moneyWithdraw();
    void showAccountInfo() const;
    // ~Account();
};

#endif
