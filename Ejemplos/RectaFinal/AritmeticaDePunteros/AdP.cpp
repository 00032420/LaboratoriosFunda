#include <iostream>
using namespace std;

int main(){
    int arr[] = {13,-4,6,21,8}, *p, i;

    cout << "Recorrer un arreglo con un puntero" << endl << endl;

    p = arr;

    cout << "Los elementos del arreglo son: " << endl;
    for(i = 0; i < 5; i++)
        cout << "Elemento " << i << " Direccion: " << (p+i) << " = " << *(p+i) << endl;
    cout << endl;
    return 0;
}