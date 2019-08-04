#ifndef __BOUNDCHECK_ARRAY_H__
#define __BOUNDCHECK_ARRAY_H__

#include "Account.h"
#include "BankingHeader.h"
//typedef Account * Accountptr;

template <typename T>
class BoundCheckArray{
private:
    T * arr;
    int len;
    BoundCheckArray(const BoundCheckArray& ref);
    BoundCheckArray& operator=(const BoundCheckArray& ref);
public:
    BoundCheckArray(int len)
        :len(len)
    {
        arr = new T[len];
    }

    T operator[] (int idx) const{
        if(idx<0||idx>=len){
            cout<<"Out of Boundary"<<endl;
            exit(1);
        }
        return arr[idx];
    }

    T& operator[] (int idx){
        if(idx<0||idx>=len){
            cout<<"Out of Boundary"<<endl;
            exit(1);
        }
        return arr[idx];
    }

    ~BoundCheckArray(){
        delete []arr;
    }
};

#endif
