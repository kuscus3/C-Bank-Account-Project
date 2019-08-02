#include <iostream>
#define NAME_LENGTH 100
using namespace std;

typedef struct Accounts
{
    int id;
    char name[NAME_LENGTH];
    int money;
} Account;

Account accarr[200];
int numOfUsers = 0;

int main(void){
    int choice;
    while(1){
        cout<< "-----Menu-----"<<endl;
        cout<<"1. Create Account"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Show Account Info"<<endl;
        cout<<"5. End Program"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
            case 1:
            {
                cout<<"[Create Account]"<<endl;
                cout<<"Account ID: ";
                cin>>accarr[numOfUsers].id;
                cout<<"Name: ";
                cin>>accarr[numOfUsers].name;
                cout<<"Input money: ";
                cin>>accarr[numOfUsers].money;
                ++numOfUsers;
                break;
            }

            case 2:
            {
                int curID;
                cout<<"[Deposit]"<<endl;
                cout<<"Account ID: ";
                cin>>curID;
                for(int i=0;i<numOfUsers;++i){
                    if(curID == accarr[i].id){
                        int tempmoney;
                        cout<<"Deposit Amount: ";
                        cin>>tempmoney;
                        accarr[i].money += tempmoney;
                        cout<<"Deposit Success"<<endl;
                        break;
                    }
                    else continue;
                }
                break;
            }

            case 3:
            {
                int curID;
                cout<<"[Withdraw]"<<endl;
                cout<<"Account ID: ";
                cin>>curID;
                for(int i=0;i<numOfUsers;++i){
                    if(curID == accarr[i].id){
                        int tempmoney;
                        cout<<"Withdraw Amount: ";
                        cin>>tempmoney;
                        accarr[i].money -= tempmoney;
                        cout<<"Withdraw Success"<<endl;
                        break;
                    }
                    else continue;
                }
                break;
            }

            case 4:
            {
                for(int i=0;i<numOfUsers;++i){
                    cout<<"Account ID: "<<accarr[i].id<<endl;
                    cout<<"Name: "<<accarr[i].name<<endl;
                    cout<<"Money: "<<accarr[i].money<<endl;
                }
                break;
            }

            case 5:
                return 0;
        }
        cout<<endl; 
    }
    return 0;
}
