#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler{
private:
    Account * accarr[200];
    int numOfUsers;
public:
    AccountHandler();
    void StartingMenu(void) const;
    void createAccount(void);
    void deposit(void);
    void withdraw(void);
    void showAllInfo(void) const;
    ~AccountHandler();
    //virtual void moneyDeposit() = 0;
};

#endif
