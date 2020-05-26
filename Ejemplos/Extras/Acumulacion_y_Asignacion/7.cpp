#include <iostream>

using namespace std;

int main(){

    int a = 20;
    int k = 5;
    int j = 10;
    int m;

    //m = k++ + (a*=10) + --j;

    a = a*10;
    j = j-1;
    m = k + a + j;
    k = k+1;

    cout << m << endl;

    return 0;
}