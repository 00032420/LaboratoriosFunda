#include <iostream>

using namespace std;

int main(){
    int k = 10;
    int n = 8;
    int c;

    //k = k*2;
    //n = n/4;
    c = (k *= 2)-(n /= 4);

    cout << c << endl;
    return 0;
}