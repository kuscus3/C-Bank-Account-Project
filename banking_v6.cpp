//inheritance
#include <iostream>
#include <cstring>
#define NAME_LENGTH 100
using namespace std;


//Entity class Account
class Account
{
private:
    int id;
    char * name;
    int money;
public:
    Account(int _id, char * _name, int _money)
    {
        int len = strlen(_name)+1;
        name = new char[len];
        strcpy(name, _name);
        id=_id;
        money=_money;
    }

    Account(const Account& copyAcc)
    {
        int len = strlen(copyAcc.name)+1;
        name = new char[len];
        strcpy(name, copyAcc.name);
        id=copyAcc.id;
        money=copyAcc.money;
    }

    int getId() const { return id; }
    int getMoney() const { return money; }

    virtual void moneyDeposit(double tempmoney){
        money += tempmoney;
    }

    void moneyWithdraw(){
        int tempmoney;
        cout<<"Withdraw Amount: ";
        cin>>tempmoney;
        money -= tempmoney;
        cout<<"Withdraw Success"<<endl;
    }

    void showAccountInfo() const {
        cout<<"Account ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Money: "<<money<<endl;
        cout<<endl;
    }

    ~Account(){
        delete []name;
    }
};

class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int _id, char * _name, int _money, int _interest)
        :Account(_id, _name, _money), interest(_interest)
    { }

    void moneyDeposit(double tempmoney){
        int interestempmoney = tempmoney * (1+interest/100.0);
        Account::moneyDeposit(interestempmoney);
    }
};

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

//control class AccountHandler
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

AccountHandler::AccountHandler() :numOfUsers(0)
{ }

void AccountHandler::StartingMenu() const{
    cout<< "-----Menu-----"<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Show Account Info"<<endl;
    cout<<"5. End Program"<<endl;
    cout<<"Choice: ";
}

void AccountHandler::createAccount(){
    int id, money, type, interest;
    char name[NAME_LENGTH];
    cout<<"[Choose Account Type]"<<endl;
    cout<<"1. Savings Account "<<"2. Credit Trust Account"<<endl;
    cout<<"Choice: ";
    cin>>type;
    if(type==1){
        cout<<"[Create Savings Account]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Input money: ";
        cin>>money;
        cout<<"Interest rate: ";
        cin>>interest;
        accarr[numOfUsers] = new NormalAccount(id, name, money, interest);
        ++numOfUsers;
    } else if(type==2){
        int rating;
        cout<<"[Create Credit Trust Account]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Input money: ";
        cin>>money;
        cout<<"Interest rate: ";
        cin>>interest;
        cout<<"Credit rating(1toA, 2toB, 3toC): ";
        cin>>rating;
        switch(rating)
        {
            case 1:
                accarr[numOfUsers] = new HighCreditAccount(id, name, money, interest, 7);
                break;
            case 2:
                accarr[numOfUsers] = new HighCreditAccount(id, name, money, interest, 4);
                break;
            case 3:
                accarr[numOfUsers] = new HighCreditAccount(id, name, money, interest, 2);
                break;
        }
        ++numOfUsers;
    } else{
        cout<<"Not Accepted"<<endl;
        exit(1);
    }
}

void AccountHandler::deposit(){
    int curID;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: ";
    cin>>curID;
    for(int i=0;i<numOfUsers;++i){
        if(curID == accarr[i]->getId()){
            int tempmoney;
            cout<<"Deposit Amount: ";
            cin>>tempmoney;
            accarr[i]->moneyDeposit(tempmoney);
            cout<<"Deposit Success"<<endl;
            break;
        }
        else continue;
    }
}

void AccountHandler::withdraw(){
    int curID;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: ";
    cin>>curID;
    for(int i=0;i<numOfUsers;++i){
        if(curID == accarr[i]->getId()){
            accarr[i]->moneyWithdraw();
            break;
        }
        else continue;
    }
}

void AccountHandler::showAllInfo() const{
    //cout<<numOfUsers<<endl;
    for(int i=0;i<numOfUsers;++i){
        accarr[i]->showAccountInfo();
    }
}

AccountHandler::~AccountHandler(){
    for(int i=0;i<numOfUsers;++i){
        delete accarr[i];
    }
}

int main(void){
    AccountHandler handler;
    while(1){
        int choice;
        handler.StartingMenu();
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
                handler.createAccount();
                break;

            case 2:
                handler.deposit();
                break;

            case 3:
                handler.withdraw();
                break;

            case 4:
                handler.showAllInfo();
                break;

            case 5:
                return 0;
        }
        cout<<endl;
    }
    return 0;
}
