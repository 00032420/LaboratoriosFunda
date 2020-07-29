#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
const int longCad = 12;
using namespace std;
struct registro{
char nombre[longCad + 1];
float nota1;
float nota2;
float nota3;
float notaPromedio;
};
void agregar(void);
void modificar(void);
void eliminarRegistros(void);
void mostrarListado(void);
int main(void)
{
int opcion;
do{
cout << endl;
cout << "MANTENIMIENTO DE ARCHIVO DE NOTAS" << endl << endl;
cout << "Menú de opciones:" << endl;
cout << "1) Agregar estudiantes" << endl;
cout << "2) Modificar registros" << endl;
cout << "3) Mostrar listado" << endl;
cout << "4) Eliminar contenido del archivo" << endl;
cout << "5) Salir" << endl;
cout << "Elija su poción: ";
cin >> opcion;
switch(opcion){
case 1:
agregar();
break;
case 2:
modificar();
break;
case 3:
mostrarListado();
break;
case 4:
eliminarRegistros();
break;
case 5:
break;
default:
cout << "Opción no válida" << endl;
}
}while(opcion != 5);
cout << endl;
return 0;
}
void agregar(void)
{
ofstream archivoSalida;
archivoSalida.open("cuadroNotas.dat", ios::out | ios::app | ios::binary);
registro estudiante;
char continuar;
string cad;
cout << endl;
cout << "GRABACIÓN DE ESTUDIANTES Y NOTAS EN UN ARCHIVO" << endl << endl;
do{
cout << "¿Desea introducir un estudiante (s/n)? ";
cin >> continuar;
cin.ignore(100, '\n');
if(continuar == 's'){
cout << "Digite los siguientes datos:" << endl;
cout << "Nombres: ";
getline(cin, cad, '\n');
strncpy(estudiante.nombre, cad.c_str( ), longCad);
estudiante.nombre[longCad]='\0';
cout << "Nota 1: ";
cin >> estudiante.nota1;
cout << "Nota 2: ";
cin >> estudiante.nota2;
cout << "Nota 3: ";
cin >> estudiante.nota3;
cin.ignore(100, '\n');
archivoSalida.write((char *) &estudiante, sizeof(estudiante));
}
}while(continuar == 's');
archivoSalida.close();
}
void modificar(void)
{
fstream archivo;
archivo.open("cuadroNotas.dat", ios::in | ios::out | ios::binary);
registro estudiante;
char continuar, modificar;
string cad;
cout << endl;
cout << "MODIFICACIÓN DE REGISTROS DE ESTUDIANTES" << endl << endl;
do{
cout << "¿Visualizar el siguiente registro (s/n)? ";
cin >> continuar;
cin.ignore(100, '\n');
if(continuar == 's'){
if(archivo.read((char *) &estudiante, sizeof(estudiante))){
cout << estudiante.nombre << endl;
cout << estudiante.nota1 << endl;
cout << estudiante.nota2 << endl;
cout << estudiante.nota3 << endl;
cout << "¿Desea modificar este registro (s/n)? ";
cin >> modificar;
cin.ignore(100, '\n');
if(modificar == 's'){
cout << "Digite nuevos datos:" << endl;
cout << "Nombres: ";
getline(cin, cad, '\n');
strncpy(estudiante.nombre, cad.c_str( ), longCad);
estudiante.nombre[longCad]='\0';
cout << "Nota 1: ";
cin >> estudiante.nota1;
cout << "Nota 2: ";
cin >> estudiante.nota2;
cout << "Nota 3: ";
cin >> estudiante.nota3;
cin.ignore(100, '\n');
archivo.seekp(-sizeof(estudiante), ios_base::cur);
archivo.write((char *) &estudiante, sizeof(estudiante));
}
}
else{
cout << "Ya no hay más registros de estudiantes" << endl << endl;
continuar = 'n';
}
}
}while(continuar == 's');
archivo.close();
}
void eliminarRegistros(void)
{
ofstream archivoSalida;
archivoSalida.open("cuadroNotas.dat", ios::out | ios::binary);
archivoSalida.close( );
cout << "Registros de estudiantes eliminados" << endl << endl;
}
void mostrarListado(void)
{
ifstream archivoEntrada;
archivoEntrada.open("cuadroNotas.dat", ios::in | ios::binary);
registro estudiante;
cout << endl;
cout << "LISTADO DE ESTUDIANTES Y NOTAS DEL ARCHIVO" << endl << endl;
while(archivoEntrada.read((char *) &estudiante, sizeof(estudiante))){
cout << estudiante.nombre << endl;
cout << estudiante.nota1 << endl;
cout << estudiante.nota2 << endl;
cout << estudiante.nota3 << endl;
}
cout << endl << "FIN de archivo" << endl;
archivoEntrada.close();
}