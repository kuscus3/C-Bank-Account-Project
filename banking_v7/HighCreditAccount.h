#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int rating;
public:
    HighCreditAccount(int _id, char * _name, int _money, double _interest, int _rating)
        :NormalAccount(_id, _name, _money, _interest), rating(_rating)
    { }

    void moneyDeposit(double tempmoney){
        NormalAccount::moneyDeposit(tempmoney);
        int interestempmoney = tempmoney * (rating/100.0);
        Account::moneyDeposit(interestempmoney);
    }
};

#endif
