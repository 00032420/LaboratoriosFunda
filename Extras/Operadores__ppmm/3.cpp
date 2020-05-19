#include <iostream>

using namespace std;

int main(){

    int a = 20;
    int b = 5;
    int c = 3;
    int m;

    //a = a/10;
    //b = b+1;
    //c = c-1;
    m = (a/=10) + ++b * --c;

    cout << m << endl;

    return 0;
}