#ifndef __STRING_H__
#define __STRING_H__

#include "BankingHeader.h"

class String{
private:
    int len;
    char * name;
public:
    String();
    String(const char * _name);
    String(const String& str);
    String& operator=(const String& str);
    String operator+(const String& str);
    String& operator+=(const String& str);
    bool operator==(const String& str);
    ~String();

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
};

#endif
