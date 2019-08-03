#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account * Accountptr;

class BoundCheckAccountPtrArray{
private:
    Accountptr * arr;
    int len;
    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& ref);
    BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& ref);
public:
    BoundCheckAccountPtrArray(int len);
    Accountptr operator[] (int idx) const;
    Accountptr& operator[] (int idx);
    ~BoundCheckAccountPtrArray();
};

#endif
