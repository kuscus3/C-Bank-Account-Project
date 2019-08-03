#include "BankingHeader.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
    :len(len)
{
    arr = new Accountptr[len];
}

Accountptr BoundCheckAccountPtrArray::operator[] (int idx) const{
    if(idx<0||idx>=len){
        cout<<"Out of Boundary"<<endl;
        exit(1);
    }
    return arr[idx];
}

Accountptr& BoundCheckAccountPtrArray::operator[] (int idx){
    if(idx<0||idx>=len){
        cout<<"Out of Boundary"<<endl;
        exit(1);
    }
    return arr[idx];
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray(){
    delete []arr;
}
