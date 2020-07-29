#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int *p = NULL;
    p = (int *)malloc(sizeof(int) * 10);
    *p = 253;

    cout << endl;
    cout << "Primera prueba con memoria dinamica" << endl << endl;

    cout << "p apunta a la direccion: " << p << endl;

    cout << "Contenido almacenado en esa direccion: " << *p << endl;

    free(p);
    p = NULL;

    cout << " p apunta a la direccion: " << p << endl;

    cout << endl;
    return 0;
}