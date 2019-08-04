#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int _id, String _name, int _money, int _interest)
        :Account(_id, _name, _money), interest(_interest)
    { }

    void moneyDeposit(double tempmoney){
        int interestempmoney = tempmoney * (1+interest/100.0);
        Account::moneyDeposit(interestempmoney);
    }
};

#endif
