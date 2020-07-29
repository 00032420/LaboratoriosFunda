#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string arr[25];
    int i,k;

    cout << endl;
    cout << "Leer frases desde un archivo" << endl << endl;

    ifstream archivo;
    archivo.open("archivo08.txt");

    i = 0;
    while(!archivo.eof())
        getline(archivo, arr[i++], '\n');

    cout << "Las frases de los archivos son: " << endl;
    for(k = 0; k < i; k++)
        cout << arr[k] << endl;
    
    archivo.close();
    return 0;
}