#include <iostream>
using namespace std;
void desplegarArreglo(int[]);

int main(void){
    int a[6] = {2,14,7,-2,10,25};

    cout << endl;

    cout << "Pasando un arreglo a una funcion" << endl << endl;

    desplegarArreglo(a);

    cout << endl;
    return 0;
}

void desplegarArreglo(int x[]){
    int i;
    cout << "Los elementos del arreglo son:" << endl;
    for(i = 0; i < 6; i++)
        cout << x[i] << " ";
    cout << endl;
}