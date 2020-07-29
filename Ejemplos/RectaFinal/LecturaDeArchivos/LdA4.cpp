#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string nombre;
    int cantidad;
    float precio;
    
    cout << endl;
    cout << "Leer palabra por palabra desde un archivo" << endl << endl;

    ifstream archivo;
    archivo.open("archivo10.txt");

    while(!archivo.eof()){
        archivo >> nombre;
        archivo >> cantidad;
        archivo >> precio;
        cout << "Se compraron " << cantidad << " unidades de ";
        cout << nombre << " a $" << precio << endl;
    }

    archivo.close();
    cout << endl;
    return 0;
}