#include <iostream>
using namespace std;

int main(){

    int b = 13;
    int c;

    c = (b*=130) + (b%5);

    cout << c << endl;
    
    return 0;
}