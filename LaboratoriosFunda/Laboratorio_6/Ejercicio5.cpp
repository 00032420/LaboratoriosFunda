#include <iostream>
using namespace std;

int main(){
    int impares[100] = {0};
    int contador = 0;
    for(int i = 0; contador < 100; i++){
        if(i%2 != 0){
            impares[contador] += i;
            contador++;
        }
    }

    for(int i = 99; i >= 0; i--){
        cout << impares[i] << endl;
    }

    return 0;
}