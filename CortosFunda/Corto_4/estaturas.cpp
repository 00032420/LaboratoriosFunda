#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Función que calcula la media del arreglo
float media(float estaturas[]){
    float sumatoria = 0.00;
    for(int i = 0; i < 25; i++){
        sumatoria += estaturas[i];
    }
    return sumatoria/25;
}

//Función que compara las estaturas con la media
void comparar(float estaturas[], float media,int *sobre, int *debajo){
    //Se itera sobre cada elemento del arreglo
    for(int i = 0; i < 25; i++){
        //SI este es mayor que la media, el contador sobre aumenta en uno
        if(estaturas[i] > media){
            *sobre+=1;
        } else if(estaturas[i] < media){
            //Si este está por debajo, ese contador aumenta en uno
            *debajo+=1;
        }
    }
}

int main(){
    //Se definen las variables
    float estaturas[25];
    int sobre = 0,debajo = 0;
    float m;

    cout << "Ingrese las estaturas en metros." << endl;
    //Se solicita ingresar las estaturas
    for(int i = 0; i < 25; i++){
        cout << "Ingrese la estatura #" << i+1 << ": ";
        cin >> estaturas[i];
    }
    //Se calcula la media y se compara con las estaturas.
    m = media(estaturas);
    //Se aproxima el valor a dos decimales
    m = floor((m*100)+.5) /100;
    comparar(estaturas, m, &sobre, &debajo);
    //Se muestran los resultados
    cout << "La media de las estaturas es " << fixed << setprecision(2) << m << " metros." << endl;
    cout << "Hay " << sobre << " alumnos con estatura arriba de la media." << endl;
    cout << "Hay " << debajo << " alumnos con estatura debajo de la media." << endl;
    return 0;
}