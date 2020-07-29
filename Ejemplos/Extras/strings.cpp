#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str1 = "Hello";
    string str2 = "World";
    string str3;
    int len;

    // copy str1 into str3
str3 = strcpy(str3,str1);
cout << "str3 : " << str3 << endl;
// joins str1 and str2
str3 = strcat(str1,str2);
cout << "str1 + str2 : " << str3 << endl;
// total length of str3 after concatenation
len = strlen(str3);
cout << "strlen(str3) : " << len << endl;
}