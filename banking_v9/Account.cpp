#include "BankingHeader.h"
#include "Account.h"


Account::Account(int _id, String _name, int _money)
{
    // int len = strlen(_name)+1;
    // name = new char[len];
    // strcpy(name, _name);
    name=_name;
    id=_id;
    money=_money;
}

// Account::Account(const Account& copyAcc)
// {
//     int len = strlen(copyAcc.name)+1;
//     name = new char[len];
//     strcpy(name, copyAcc.name);
//     name=copyAcc.name;
//     id=copyAcc.id;
//     money=copyAcc.money;
// }
//
// Account& Account::operator=(const Account & copy)
// {
//     id = copy.id;
//     money = copy.money;
//     delete []name;
//     name = new char[strlen(copy.name)+1];
//     strcpy(name, copy.name);
//     name = copy.name;
//     return *this;
// }

int Account::getId() const { return id; }
int Account::getMoney() const { return money; }

void Account::moneyDeposit(double tempmoney){
    money += tempmoney;
}

void Account::moneyWithdraw(){
    int tempmoney;
    cout<<"Withdraw Amount: ";
    cin>>tempmoney;
    money -= tempmoney;
    cout<<"Withdraw Success"<<endl;
}

void Account::showAccountInfo() const {
    cout<<"Account ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Money: "<<money<<endl;
    cout<<endl;
}

// Account::~Account(){
//     delete []name;
// }
