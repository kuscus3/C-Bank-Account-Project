//control class
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

    void moneyDeposit(){
        int tempmoney;
        cout<<"Deposit Amount: ";
        cin>>tempmoney;
        money += tempmoney;
        cout<<"Deposit Success"<<endl;
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
    int id, money;
    char name[NAME_LENGTH];
    cout<<"[Create Account]"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Input money: ";
    cin>>money;
    accarr[numOfUsers] = new Account(id, name, money);
    ++numOfUsers;
}

void AccountHandler::deposit(){
    int curID;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: ";
    cin>>curID;
    for(int i=0;i<numOfUsers;++i){
        if(curID == accarr[i]->getId()){
            accarr[i]->moneyDeposit();
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
