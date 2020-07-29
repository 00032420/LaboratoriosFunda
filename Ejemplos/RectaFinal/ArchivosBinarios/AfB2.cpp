#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int entero;

    cout << endl;
    cout << "Grabar enteros en un archivo de texto" << endl << endl;

    ofstream archivo;
    archivo.open("misEnteros_b.txt", ios::app);

    cout << "Digite un entero o Crtl-Z para finalizar: ";

    while(cin >> entero){
        archivo.write((char *) &entero, sizeof(int));
        cout << "Digite un entero o Crtl-Z para finalizar: ";
    }

    archivo.close();
    cout << endl;
    return 0;
}