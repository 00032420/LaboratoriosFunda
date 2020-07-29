#include <iostream>
using namespace std;

//Función para rellenar los arreglos 
void leerArreglo(int numeros[], int longitud){
    for(int i= 0; i < longitud; i++){
        cin >> numeros[i];
    }
}

//Funcion que cuenta el argumento como elemento del arreglo
int contarNumero(int arreglo[], int longitud, int numero){
    int contador = 0;
    for(int i = 0; i < longitud; i++){
        if(arreglo[i] == numero) contador++;
    }
    return contador;
}

int main(){
    //Se declaran las variables
    int arreglo[50] = {0};
    int longitud;
    int numero;

    //Se solicita la longitud de los arreglos a operar
    cout << "Ingrese la longitud del arreglo: ";
    cin >> longitud;
    if(longitud > 50){
        cout << "La longitud de los arreglos no debe ser mayor a 50." << endl;
        return 0;
    }
    //Se solicita la longitud del arreglo
    cout << "Ingrese los elementos del arreglo:" << endl;
    leerArreglo(arreglo, longitud);
    //Se soclitan los elementos del arreglo
    cout << "Ingrese que numero a contar como elemento del arreglo: ";
    cin >> numero;
    //se muestra cuantas veces aparece el numero como elemento del arreglo. 
    cout << "El numero " << numero 
         << " aparece " <<  contarNumero(arreglo,longitud,numero) 
         << " veces como elemento del arreglo." << endl;


    return 0;
}