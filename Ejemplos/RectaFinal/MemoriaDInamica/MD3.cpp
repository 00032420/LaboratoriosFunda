#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int *r, *p;

    cout << endl;
    cout << "Tercera prueba con memoria dinamica" << endl << endl;

    r = (int*) malloc(10*sizeof(int));

    p = r;

    *p = 25;
    p = p+1;
    *p = 30;
    p = p+1;
    *p = 35;
    p = p +1;
    *p = 40;

    p = r;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    free(r);
    r = NULL;
    free(p);
    p = NULL;

    cout << "r apunta a la direccion: " << r << endl;
    cout << "p apunta a la direccion: " << p << endl;

    cout << endl;
    return 0;
}