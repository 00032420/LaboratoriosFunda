#include <fstream>
#include <iostream>
using namespace std;

int main(){
    unsigned char letra;
cout << endl;
cout << "AVANZAR Y RETROCEDER EN UN ARCHIVO DE TEXTO" << endl << endl;
ifstream abecedario;
abecedario.open("abecedario.txt", ios::in);
cout << "Archivo abierto" << endl;
cout << "La posición inicial del archivo es : " << abecedario.tellg( ) << endl;
abecedario >> letra;
cout << "Carácter leído: " << letra;
cout << "\nEstamos en la posición " << abecedario.tellg( ) << " del archivo" << endl;
abecedario >> letra;
cout << "Carácter leído: " << letra;
cout << "\nEstamos en la posición " << abecedario.tellg( ) << " del archivo" << endl;
cout << "Avanzar leyendo unos cuantos" << endl;
for(int i = 1; i < 16; i++)
abecedario >> letra;
cout << "Estamos en la posición " << abecedario.tellg( ) << " del archivo" << endl;

cout << "Retrodecederemos 4 caracteres" << endl;
abecedario.seekg(-4, ios_base::cur);
cout << "Estamos en la posicion " << abecedario.tellg() << " del archivo" << endl;

cout << "Leyendo contenido restante del archivo:" << endl;

while(abecedario >> letra){
    cout << letra << '\t';
}
    abecedario.clear();
    cout <<"\nNos colocamos al inicio de nuevo" << endl;
    abecedario.seekg(0); //abecedario.seekg(0,ios_base::beg);

    cout << "Contenido completo del archivo:" << endl;
    while(abecedario >> letra){
        cout << letra << '\t';
    }

    cout << "\nEstamos en la posicion " << abecedario.tellg() << " del archivo" << endl;
    abecedario.clear();
    cout << endl;
    cout << "Otra vez contenido completo del archivo: " << endl;
    abecedario.seekg(0);
    while(abecedario >> letra){
        cout << letra << '\t';
    }
    cout << "\n Estamos en la posicion " << abecedario.tellg() << " del archivo" << endl;

    abecedario.close();

    cout << endl;

    return 0;
}