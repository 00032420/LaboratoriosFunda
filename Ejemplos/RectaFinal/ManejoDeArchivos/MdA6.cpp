#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string frase;
    cout << "Llenar un archivo con datos del teclado" << endl << endl;

    ofstream archivo;
    archivo.open("archivo06.txt");

    cout << "Digite una frase o Crtl-Z para finalizar: " << endl;
    while(getline(cin, frase, '\n')){
        archivo << frase << endl;
        cout << "Digite una frase o Crtl-Z para finalizar:" << endl;
    }

    archivo.close();
    return 0;
}