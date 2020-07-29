#include <iostream>
#include <cmath>
using namespace std;
bool primo(int);

int main(){
    int n;
    

    cout << endl;
    cout << "Determinar si un numero es primo." << endl << endl;

    cout << "Digite un entero: ";
    cin >> n;

    if(n == 1)
        cout << n << " no es primo." << endl;
    else 
        if(n <=0)
            cout << n << ": Este numero no aplica.";
        else{
            

            if(primo(n) == true)
                cout << n << " es primo" << endl;
            else 
                cout << n << " no es primo" << endl;
        }
    return 0;
}

bool primo(int n){
    bool esPrimo = true;
    int i;

    i=2;
            while(i <= (int) sqrt(n) && esPrimo == true){
                if(n%i == 0)
                    esPrimo = false;
                i =  i + 1;
            }
    return esPrimo;
}