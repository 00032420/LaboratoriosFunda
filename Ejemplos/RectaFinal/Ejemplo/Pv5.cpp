#include <iostream>
#include <cmath>

using namespace std;
bool primo(int);
void imprimirArreglo(int [ ], int);

int main(){
    int a,b,i, primos[100], k;

    cout << endl;
    cout << "Determinar numeros primos en un intervalo" << endl << endl;

    cout << "Proporcione los extremos del intervalo: " << endl;
    cout << "Digite a: ";
    cin >> a;
    cout << "Digite b: ";
    cin >> b;

    k = 0;

    for(i = a; i <= b; i++)
        if(primo(i) == true){
            primos[k] = i;
            cout << primos[k] << endl;
            k = k +1;
        }

    imprimirArreglo(primos, k);
    
    cout << endl;
    return 0;
}

bool primo(int n){
    int i;

    if(n <= 1)
     return false;
    else{
        i = 2;
        while(i <= (int) sqrt(n)){
            if(n%i == 0)
                return false;
            i = i +1;
        }
    }
    return true;
}

void imprimirArreglo(int arr[], int k){
    cout << endl << "Primos: " << endl; 
    for(int i = 0; i < k; i++)
        cout << arr[k] << "  ";
}