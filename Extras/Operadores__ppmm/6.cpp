#include <iostream>

using namespace std;

int main(){

    int a = 20;
    int j = 10;
    int m;

    //m = a*10 + j++;

    a = a*10;
    m = a + j;
    j = j+1;

    cout << m << endl;
    return 0;
}