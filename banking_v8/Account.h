#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int id;
    char * name;
    int money;
public:
    Account(int _id, char * _name, int _money);
    Account(const Account& copyAcc);
    Account & operator=(const Account & ref);
    int getId() const;
    int getMoney() const;
    virtual void moneyDeposit(double tempmoney);
    void moneyWithdraw();
    void showAccountInfo() const;
    ~Account();
};

#endif
