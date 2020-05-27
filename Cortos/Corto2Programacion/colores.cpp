#include <iostream>
#include <string>

using namespace std;

int main(){
    //Se declaran las variables
    string colores[5] = {"Blanco", "Amarillo", "Rojo", "Azul","Negro"};
    int dolares[5], c; 
    c = 0;
    //Se le asigna un numero distinto al azar (entre 1 y 100) a cada elemento de 'dolares'
    for(int i = 0; i < 5; i++) dolares[i] = (rand() % 100 + 1);

    //Se muestra el menu
    for(int i = 0; i < 5; i++) cout << i+1 << ") " << colores[i] << endl;
    //Se solicita la seleccion de un color, introuciendo un entero valido dentro del rango
    while(cin.fail() || !(c>=1 && c <= 5)){
    cout << endl << "Seleccione un color ingresando el numero que le corresponda: ";
    cin >> c; 
    cin.clear(); 
    cin.ignore();
    }
    //Se muestra el dinero asignado en la casilla del color seleccionado
    cout << "Ha seleccionado el color " << colores[c-1] << endl;
    cout << "Ha ganado $" << dolares[c-1] << "." << endl;

    return 0;
}