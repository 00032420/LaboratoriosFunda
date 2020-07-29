#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,i;
    bool esPrimo = true;

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
            i=2;
            while(i <= (int) sqrt(n)){
                if(n%i == 0)
                    esPrimo = false;
                i =  i + 1;
            }

            if(esPrimo == true)
                cout << n << " es primo" << endl;
            else 
                cout << n << " no es primo" << endl;
        }
    return 0;
}