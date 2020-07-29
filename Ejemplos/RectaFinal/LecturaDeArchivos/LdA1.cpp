#include <iostream>
#include <fstream>

using namespace std;

int main(){
    unsigned char car;
    unsigned int x;

    cout << endl;
    cout << "Leer datos desde un archivo" << endl << endl;
    ifstream archivo;
    archivo.open("archivo07.txt");

    car = archivo.get();
    x = archivo.get();

    cout << "El caracter leido es: " << car << endl;
    cout << "El siguiente caracter tiene el valor: " << x;
    cout << " en la tabla ASCII" << endl;

    archivo.close();
    cout << endl;
    return 0;
}