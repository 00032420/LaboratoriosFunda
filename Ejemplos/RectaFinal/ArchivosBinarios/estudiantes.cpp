#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

const int longCad = 12;
using namespace std;

struct estudiante {
    char nombre[longCad + 1];
    float nota1;
    float nota2;
    float nota3;
    float notaPromedio;
};

int main(){
    ofstream archivoSalida;
    archivoSalida.open("cuadroNotas", ios::out | ios::binary);

    estudiante registro;
    string cad;
    int n,i;
    cout << endl;
    cout << "Grabación de estructuras en un archivo" << endl << endl;
    cout << "¿Cuantos estudiantes?";
    cin >> n;
    cin.ignore(100,'\n');
    estudiante listado[100];

    cout << "Digite nombre, apellido y las tres notas:" << endl;
    for(i = 0; i < n; i++){
        cout << "Nombres: ";
        getline(cin, cad, '\n');
        strncpy(listado[i].nombre, cad.c_str(), longCad);
        listado[i].nombre[longCad] = '\n';
        cout << "Nota 1: ";
        cin >> listado[i].nota1;
        cout << "Nota 2: ";
        cin >> listado[i].nota2;
        cout << "Nota 3: ";
        cin >> listado[i].nota3;
        cin.ignore(100,'\n');
        archivoSalida.write( (char *)&listado[i], sizeof(listado[i]));
    }
    archivoSalida.close();
    cout << "Los datos del arreglo son: " << endl;

    for(i = 0; i < n; i++){
        cout << listado[i].nombre << "-->" << strlen(listado[i].nombre) << endl;
        cout << "Nota 1: " << listado[i].nota1 << endl;
        cout << "Nota 2: " << listado[i].nota2 << endl;
        cout << "Nota 3: " << listado[i].nota3 << endl;
    }

    ifstream archivoEntrada;
    archivoEntrada.open("cuadroNotas", ios::in | ios::binary);
    cout << "Contenido del archivo: " << endl;
    while(archivoEntrada.read( (char *)&registro, sizeof(listado[i]))){
        cout << registro.nombre << endl;
        cout << registro.nota1 << endl;
        cout << registro.nota2 << endl;
        cout << registro.nota3 << endl;
    }
    archivoEntrada.close();
    cout << endl;
    return 0;
}