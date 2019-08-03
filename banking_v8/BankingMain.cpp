//operator overloading
#include "BankingHeader.h"
#include "AccountHandler.h"
#include "AccountHandler.cpp"


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
