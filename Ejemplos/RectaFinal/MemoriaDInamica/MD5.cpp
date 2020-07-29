#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    int *r, *p;

    cout << endl;
    cout << "Cuarta prueba con memoria dinamica" << endl << endl;

    r = new int[10];

    p = r;

    *p = 25;
    p = p+1;
    *p = 30;
    p = p+1;
    *p = 35;
    p = p+1;
    *p = 40;

    p = r;

    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;
    p = p+1;
    cout << "El contenido de la direccion " << p << " es: " << *p << endl;

    delete [] r;
    r = NULL;
    p = NULL;

    cout << "r apunta a la direccion: " << r << endl;
    cout << "p apunta a la direccion: " << p << endl;
    cout << endl;
    return 0;
}