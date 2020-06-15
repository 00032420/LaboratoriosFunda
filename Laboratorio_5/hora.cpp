#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int leerEntero(string numero, int limite){ //Se pone como argumento el string del numero
    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890") != string::npos || !(stoi(numero) >= 0 && stoi(numero) <= limite)){
        //Se advierte el error
        cout << "Numero invalido.El numero debe ser mayor o igual a 0 y menor o igual a " << limite << endl << endl;
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior 
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }
    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return atof(numero.c_str() );
}

void sumarSegundo(int *hora, int *minutos, int *segundos){
    bool cambioS,cambioM;
    if(*segundos == 59){
        *segundos = 0;
        cambioS = true;
        if(cambioS == true){
            if(*minutos == 59){*minutos=0;cambioM = true;}
                else{++*minutos;}
            if(cambioM == true){
            if(*hora == 23){*hora=0;}else{
            ++*hora;}
        }
    } 
    } else {*segundos+=1;}
}

//Función para repetir la operación.
bool reiniciar(bool repetir){
    cout << endl << "Desea repetir la operacion? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayuscula o minuscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;  
}

main(){
    bool repetir;
    do{
    string hhT,mmT,ssT;
    int hh,mm,ss;
    cout << "Ingrese la hora: ";
    hh = leerEntero(hhT,23);
    cout << "Ingrese los minutos: ";
    mm = leerEntero(mmT,59);
    cout << "Ingrese los segundos: ";
    ss = leerEntero(ssT,59);

    cout << endl << "La hora es: " << setw(2) << setfill('0') << hh << ":"
                           << setw(2) << setfill('0') << mm << ":"
                           << setw(2) << setfill('0') << ss << endl;
    sumarSegundo(&hh,&mm,&ss);
    cout << endl << "Esa hora despues de un segundo: " 
                           << setw(2) << setfill('0') << hh << ":"
                           << setw(2) << setfill('0') << mm << ":"
                           << setw(2) << setfill('0') << ss << endl;
    cout << endl;
    //Se pregunta si se quiere repetir la operacion.
    repetir = reiniciar(repetir);                      
    }while(repetir == true);
    return 0;
}