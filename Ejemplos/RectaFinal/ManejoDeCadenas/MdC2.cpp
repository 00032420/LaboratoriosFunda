#include <iostream>
#include <string>
using namespace std;

int main(){
    char cadena[10] = "1234", cad[10], *pCad;
    int i = 5, entero;
    double real;

    cout << "***** Uso de atoi: (cadena a entero)" << endl;
    entero = atoi(cadena);
    cout << "El entero es: " << entero << endl;

    cout << "***** Uso de _itoa: (entero a cadena)" << endl;
    _itoa(i, cad, 10);
    cout << "La cadena es: " << cad << endl;

    cout << "***** Uso de atof: (cadena a real)" << endl;
    real = atof("523.27");
    cout << "El real es: " << real << endl;

    cout << "***** Uso de sprintf: (real a cadena)" << endl;
    sprintf(cad, "%f", 523.27);
    cout << "La cadena es: " << cad << endl;

    cout << endl << endl;
    return 0;
}
