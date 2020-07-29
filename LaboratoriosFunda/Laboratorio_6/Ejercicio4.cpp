#include <iostream>
using namespace std;

//Función para rellenar los arreglos 
void leerArreglo(int numeros[], int longitud){
    for(int i= 0; i < longitud; i++){
        cin >> numeros[i];
    }
}

//FUnción para rellenar el arreglo resultante con la suma de cada elemento de los arreglos
void sumarArreglos(int arreglo1[], int arreglo2[], int longitud, int resultante[]){
    for(int i=0; i < longitud; i++){
        resultante[i] = arreglo1[i] + arreglo2[i];
    }
}

//Función que despliega un arreglo hasta la longitud deseada
void desplegarArreglo(int resultante[], int longitud){
    for(int i=0; i < longitud; i++){
        if(i == longitud-1){
            cout << resultante[i] << "";
        } else {
            cout << resultante[i] << ", ";
        }
    }
}

int main(){
    //Se declaran las variables
    int arreglo1[50] = {0};
    int arreglo2[50] = {0};
    int resultante[50] = {0};
    int longitud;

    //Se solicita la longitud de los arreglos a operar
    cout << "Ingrese la longitud de los arreglos: ";
    cin >> longitud;
    if(longitud > 50){
        cout << "La longitud de los arreglos no debe ser mayor a 50." << endl;
        return 0;
    }

    //Se 
    cout << "Ingrese los elementos del primer arreglo: " << endl;

    leerArreglo(arreglo1, longitud);

    cout << "Ingrese los elementos del segundo arreglo: " << endl;

    leerArreglo(arreglo2, longitud);

    sumarArreglos(arreglo1, arreglo2, longitud, resultante);
    
    cout << "El arreglo resultante es: [";
    desplegarArreglo(resultante, longitud);
    cout << "]" << endl;

    system("pause");
    return 0;
}