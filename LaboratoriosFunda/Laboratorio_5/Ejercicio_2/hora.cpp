#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

int leerEntero(string numero, int min, int limite){ //Se pone como argumento el string del numero, y los extremos de su rango
    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890") != string::npos || !(stoi(numero) >= min && stoi(numero) <= limite)){
        //Se advierte el error
        cout << "Dato invalido.El numero debe ser mayor o igual a " << min << " y menor o igual a " << limite << endl << endl;
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior 
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }
    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return atof(numero.c_str() );
}

//Se suma el segundo, si la cuenta se reinicia activa los marcadores para el reinicio de las otras variables
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
    } //Si no se debe reiniciar ninguna cuenta, simplemente aumenta el segundo en uno
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
    
    string hhT,mmT,ssT, opT;
    int hh,mm,ss, op;
    //Se muestran las opciones
    cout << "[1] - Introducir hora manualmente." << endl;
    cout << "[2] - Usar hora del sistema" << endl;
    cout << "Introduzca una opcion: ";
    op = leerEntero(opT,1,2);
    //dependiendo de la opcion del usuario, se definen las variables
    if (op == 1)
    {
        cout << "Ingrese la hora: ";
        hh = leerEntero(hhT,0,23);
        cout << "Ingrese los minutos: ";
        mm = leerEntero(mmT,0,59);
        cout << "Ingrese los segundos: ";
        ss = leerEntero(ssT,0,59);
    } else if (op == 2)
    {
        time_t theTime = time(NULL);
        struct tm *aTime=localtime(&theTime);
        hh = aTime->tm_hour;
        mm = aTime->tm_min;
        ss = aTime->tm_sec;
    }
    //Se muestra la hora actual o la hora introducida
    cout << endl << "La hora es: " << setw(2) << setfill('0') << hh << ":"
                           << setw(2) << setfill('0') << mm << ":"
                           << setw(2) << setfill('0') << ss << endl;
    //se incrementa en un segundo
    sumarSegundo(&hh,&mm,&ss);
    //Se muestra la hora un segundo despues
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