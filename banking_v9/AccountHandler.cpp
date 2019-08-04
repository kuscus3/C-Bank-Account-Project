#include "BankingHeader.h"
#include "AccountHandler.h"
#include "Account.cpp"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountArray.cpp"
#include "String.cpp"

AccountHandler::AccountHandler() :numOfUsers(0), accarr(200)
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
    // char name[NAME_LENGTH];
    String name;
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
