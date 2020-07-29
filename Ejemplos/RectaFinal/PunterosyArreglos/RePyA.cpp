#include <iostream>
using namespace std;

int main(void){
    int a[10] = {5,10,15,20,25,30,35,40,45,50};

    cout << "El primer valor de a es: " << a[0] << endl;
    cout << "El primer valor de a es: " << *a << endl;

    cout << "La dirección donde inicia a es: " << a << endl;
    cout << endl;

    int b[] = {23,46,12,28,1,-10,0,-5}, i;
    cout << endl;
    cout << "Direcciones de cada casilla delarreglo" << endl << endl;

    for(int i = 0; i < 8; i++){
        cout << "El elemento " << a[i];
        cout << " esta en la direcion " << &a[i] << endl;
    }
    cout << endl;
    return 0;
    
}