#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream archivo;
    archivo.open("elArchivo.txt");

    if(!archivo)
        cout << "El archivo no existe" << endl;
    else 
        cout << "El archivo si existe" << endl;

    archivo.close();
    return 0;
}