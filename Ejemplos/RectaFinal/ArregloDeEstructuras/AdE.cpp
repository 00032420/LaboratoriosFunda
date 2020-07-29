#include <iostream>
#include <string>
#include <string.h>

const int longCad = 12; 

using namespace std;

struct estudiante{
    char nombre[longCad + 1];
    float nota1;
    float nota2;
    float nota3;
    float notaPromedio;
};

int main(){
    char c;
    string cad;
    int n, i, j;
    cout << endl;
    cout << "Prueba de arreglo de estructuras" << endl << endl;

    cout << "Cuantos estudiantes? ";
    cin >> n;
    //while ((c = getchar()) != '\n' && c != EOF);
    //fflush(stdin);
    cin.ignore(100, '\n');
    estudiante listado[n];

    cout << "Digite nombre, apellido y las tres notas: " << endl;
    for(i =0;i < n; i++){
        cout << "Nombres: ";
        getline(cin, cad, '\n');
        strncpy(listado[i].nombre, cad.c_str(), longCad);
        listado[i].nombre[longCad]='\0';
        cout << "Nota 1: ";
        cin >> listado[i].nota1;
        cout << "Nota 2: ";
        cin >> listado[i].nota2;
        cout << "Nota 3: ";
        cin >> listado[i].nota3;
        cin.ignore(100, '\n');
    }

    cout << "Los datos del arreglo son:" << endl;
    for(i = 0; i < n; i++){
        cout << listado[i].nombre << "-->" << strlen(listado[i].nombre) << endl;
        cout << "Nota 1: " << listado[i].nota1 << endl;
        cout << "Nota 2: " << listado[i].nota2 << endl;
        cout << "Nota 3: " << listado[i].nota2 << endl;
    }

    return 0;

}