#include "BankingHeader.h"
#include "String.h"

String::String(){
    len = 0;
    name = NULL;
}

String::String(const char * _name){
    //int len = str.len <-- Mistake to create new integer variable(bad_alloc called)
    len = strlen(_name)+1;
    name = new char[len];
    strcpy(name, _name);
}

String::String(const String& str){
    //int len = str.len <-- Mistake to create new integer variable(bad_alloc called)
    len = str.len;
    name = new char[len];
    strcpy(name, str.name);
}

String& String::operator=(const String& str){
    if(name != NULL)
        delete []name;
    len = str.len;
    name = new char[len];
    strcpy(name, str.name);
    return *this;
}

String::~String(){
    if(name != NULL)
        delete []name;
}

String String::operator+(const String& str){
    char * catstr = new char[str.len+len-1];
    strcpy(catstr, name);
    strcat(catstr, str.name);
    String s(catstr);
    delete []catstr;
    return s;
}

String& String::operator+=(const String& str){
    len = len + str.len - 1;
    char * catstr = new char[len];
    strcpy(catstr, name);
    strcat(catstr, str.name);
    if(name != NULL)
        delete []name;
    name = catstr;
    return *this;
}

bool String::operator==(const String& str){
    bool ret = strcmp(str.name, name) ? false : true;
    return ret;
}

std::ostream& operator<<(std::ostream& os, const String& str){
    os<<str.name;
    return os;
}

std::istream& operator>>(std::istream& is, String& str){
    char arr[100];
    is>>arr;
    str=String(arr);
    return is;
}
