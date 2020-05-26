#include <iostream>

using namespace std;

int main(){
    int k = 10, c;

    // k = k * 2;
    //k *= 2;
    c = (k *= 2) + 3;

    cout << k << endl;
    cout << c << endl;

    return 0;
}