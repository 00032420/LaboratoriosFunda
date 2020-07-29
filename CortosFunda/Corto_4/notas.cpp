#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//Funcion que llena la matriz con las notas
void llenar(string matriz[][8], int alumnos){
    for(int fila = 1; fila < alumnos; fila++){
        cout << "Ingrese las notas del alumno " << fila << ":" << endl <<endl;
        matriz[fila][0] = "Alumno " + to_string(fila) + "  ";
        for(int columna = 1; columna < 6; columna++){
            cout << "Ingrese la nota #" << columna << ": ";
            cin >> matriz[fila][columna];
        }
        cout << endl;
    }
}

//Funcion que calcula la nota final y el estado 
void calcular(string matriz[][8], int alumnos){
    for(int fila = 1; fila < alumnos; fila++){
        float notaFinal = 0.0;
        for(int i = 1; i < 6; i++){
            //Se suma la ponderación de cada prueba
            notaFinal += stof(matriz[fila][i])*0.2;
        }
        //Se aproxima a dos decimales
        float aprox = floor((notaFinal*100)+.5) /100;
        matriz[fila][6] = to_string(aprox);
        //Se define si se aprobó o reprobó
        matriz[fila][7] = (aprox >= 6.0)? "Aprobado":"Reprobado";
        notaFinal = 0.0;
    }
}
//Funcion que despliega la matriz por medio de iteraciones en sus celdas
void desplegarMatriz(string notas[][8], int alumnos){
    for(int f = 0; f < alumnos; f++){
        for(int c = 0; c < 8; c++){
            if(f >= 1 && (c >= 1 && c <=6)){
                //Si es una casilla de nota se muestra con dos decimales 
            cout << setw(10) << fixed << setprecision(2) << stof(notas[f][c]) << "  ";
            } else{
            cout << setw(10) << notas[f][c] << "  ";
            }
        }
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;
    }
}

int main(){
    int alumnos;
    //Se solicita la cantidad de alumnos
    cout << "Ingrese el numero de alumnos: ";
    cin >> alumnos;
    alumnos++;
    cout << endl;
    //Se define la excepción
    if(alumnos > 100){
        cout << "No se pueden ingresar más de 100 alumnos. Programa finalizado.";
        return 0;
    }
    //Se definen los datos iniciales de la matriz
    string notas[100][8] = {"Nota ->", "#1", "#2", "#3", "#4", "#5", "Nota Final", "Estado"};
    //SLe llaman las funciones 
    llenar(notas,alumnos);
    calcular(notas,alumnos);
    desplegarMatriz(notas,alumnos);
    return 0;
}