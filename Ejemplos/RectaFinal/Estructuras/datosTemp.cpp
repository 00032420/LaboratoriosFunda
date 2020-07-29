#include <iostream>
using namespace std;

struct coordenadas{
    float x,y;
};

struct datosTemp{
    float temp;
    coordenadas punto;
};

void leerTemperaturas(datosTemp *, int);
void mostrarTemperaturas(datosTemp *, int);
void buscarExtremos(datosTemp *, int, datosTemp *, datosTemp*);
void mostrarExtremos(datosTemp, datosTemp);

int main(){
    int n;
    datosTemp tempMenor, tempMayor;

    cout << endl;
    cout << "Datos de temperatura en una placa" << endl << endl;

    cout << "Cuantos datos de temperatura ingresara?";
    cin >> n;
    datosTemp *temperaturas = new datosTemp[n];
    leerTemperaturas(temperaturas,n);
    mostrarTemperaturas(temperaturas,n);
    cout << "Los valores extremos son:" << endl;
    buscarExtremos(temperaturas, n, &tempMenor, &tempMayor);
    mostrarExtremos(tempMenor,tempMayor);

    cout << endl;
    return 0;
}

void leerTemperaturas(datosTemp *datos, int n){
    int i;

    cout << "Lea los valores de temperatura de la placa: " << endl;
    for(i = 0; i < n; i++){
        cout << "Introduzca x: ";
        cin >> (datos + i)->punto.x;
        cout << "Introduzca y: ";
        cin >> (datos + i)->punto.y;
        cout << "Introduzca valor de temperatura: ";
        cin >> (datos +i)->temp;
    }
}

void mostrarTemperaturas(datosTemp *datos, int n){
    int i;
    cout << "Los valores de temperatura de la placa son: " << endl;
    for(i=0; i < n; i++){
        cout << "x: ";
        cout << (datos + i)->punto.x << endl;
        cout << "y: ";
        cout << (datos + i)->punto.y << endl;
        cout << "Temperatura: ";
        cout << (datos + i)->temp << endl;
        cout << endl;
    }
}

void buscarExtremos(datosTemp *datos, int n, datosTemp *tMenor, datosTemp *tMayor){
    int i;
    *tMenor = *tMayor = *datos;

    for(i=0; i < n; i++){
        if((datos+i)->temp < tMenor->temp)
            *tMenor = *(datos+i);
        if((datos+i)->temp > tMayor->temp)
            *tMayor = *(datos+i);
    }
}

void mostrarExtremos(datosTemp menor, datosTemp mayor){
    cout << "La temperatura menor es: " << menor.temp << endl;
    cout << "Y se ubica en: (" << menor.punto.x << ", " << menor.punto.y << ")" << endl;
    cout << "La temperatura mayor es: " << mayor.temp << endl;
    cout << "Y se ubica en: (" << mayor.punto.x << ", " << mayor.punto.y << ")" << endl;
}