#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int entero, suma, n;
    float promedio;

    cout << endl;
    cout << "Leer enteros de un archivo binario" << endl << endl;

    ifstream archivo;
    archivo.open("misEnteros_b.txt");

    suma = n = 0;
    cout << "Los datos del archivo binario son: " << endl;
    while(archivo.read((char *) &entero, sizeof(int))){
        cout << entero << endl;
        suma = suma + entero;
        n = n+1;
    }

    promedio = (float) suma/n;
    cout << "El promedio d elos valores es: " << promedio << endl;
    archivo.close();

    cout << endl;
    return 0;  
}