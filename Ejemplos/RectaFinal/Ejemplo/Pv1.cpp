#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,i;
    bool esPrimo = true;

    cout << endl;
    cout << "determinar si un numero es primo" << endl << endl;

    cout << "Digite un entero: ";
    cin >> n;

    if(n == 1)
        cout << n << " no es primo." << endl;
    else 
        if(n <=0)
            cout << "Este numero no aplica.";
        else{
            for(i = 2; i <= (int) sqrt(n); i++)
                if(n%i == 0)
                    esPrimo = false;
            
            if(esPrimo == true)
                cout << n << " es primo" << endl;
            else 
                cout << n << " no es primo" << endl;
        }
    cout << endl;
    return 0;
}