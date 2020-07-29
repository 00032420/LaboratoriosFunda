#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int *r;

    cout << endl;
    cout << "Segunda prueba con memoria dinamica." << endl << endl;

    r = (int*) malloc(10* sizeof(int));

    *r = 25;
    *(r+1) = 30;
    *(r+2) = 35;
    *(r+3) = 40;

    for(int i = 0; i < 4; i++)
        cout << "El contenido de la direccion " << r+i << " es: " << *(r+i) << endl;

    free(r);
    r = NULL;

    cout << "r apunta a la direcion: " << r << endl;
    cout << endl;
    return 0;
}