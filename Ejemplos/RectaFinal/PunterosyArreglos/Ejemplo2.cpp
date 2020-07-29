#include <iostream>
using namespace std;
void llenarArreglo(int [], int);
void desplegarArreglo(int [],int);

int main(void){
    int a[100], n;

    cout << endl;
    cout << "Llenar un arreglo con valores" << endl << endl;

    cout << "Cuantos elementos quiere introducir?"; 
    cin >> n;

    llenarArreglo(a,n);
    desplegarArreglo(a,n);

    cout << endl;
    return 0;

}

void llenarArreglo(int x[], int n){
    int i;
    cout << "Digite los " << n << " elementos del arreglo: " << endl;
    for(i = 0; i < n; i++)
        cin >> x[i];
}

void desplegarArreglo(int x[], int n){
    int i;
    cout << "los elementos del arreglo son: " << endl;
    for(i=0; i < n; i++)
        cout << x[i] << "  ";
        cout << endl;
}