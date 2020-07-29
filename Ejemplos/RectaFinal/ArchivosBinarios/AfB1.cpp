#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int entero;

    cout << endl;
    cout << "Grabar enteros en un archivo de texto" << endl << endl;

    ofstream archivo;
    archivo.open("misEnteros_a.txt", ios::app);

    cout << "Digita un entero a Crtl-Z para finalizar: ";
    while(cin >> entero){
        archivo << entero << '\n';
        cout << "Digite un entero o Crtl-Z para finalizar: ";
    }
    archivo.close();
    cout << endl;
    return 0;
}