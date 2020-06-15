#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int leerEntero(string numero, int min, int limite){ //Se pone como argumento el string del numero, y los extremos de su rango
    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890") != string::npos || !(stoi(numero) >= min && stoi(numero) <= limite)){
        //Se advierte el error
        cout << "Fecha invalida.El numero debe ser mayor o igual a " << min << " y menor o igual a " << limite << endl << endl;
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior 
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }
    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return atof(numero.c_str() );
}

//Se suma unt, tomando en cuenta la duracion del mes y de si se reinician las cuentas
void sumarDia(int *year, int *mes, int *dia, int *limite){
    bool cambioD,cambioM;
    if(*dia == *limite){
        *dia = 1;
        cambioD = true;
        if(cambioD == true){
            if(*mes == 12){*mes=1;cambioM = true;}
                else{++*mes;}
            if(cambioM == true){++*year;}
    } 
    } else {*dia+=1;}
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

//Funcion que verifica si un año es bisiesto
bool bisiesto(int year){
    return (year%400 == 0 || (year%4 == 0 && !(year%100 == 0)))? true:false;
}

main(){
    bool repetir;
    do{
    string aaT,mmT,ddT, opT;
    //Se definen los dias de cada mes
    int meses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int aa,mm,dd, op;
    //Se muestran las opciones
    cout << "[1] - Introducir fecha manualmente." << endl;
    cout << "[2] - Usar fecha del sistema" << endl;
    cout << "Introduzca una opcion: ";
    op = leerEntero(opT,1,2);

    if(op == 1){
    //Se solicitan los datos
    cout << "Ingrese el a\244o: ";
    aa = leerEntero(aaT,0,9999);
    //Si el año es bisiesto febrero consta de 29 dias
    if(bisiesto(aa) == true) ++meses[1];
    cout << "Ingrese el mes: ";
    mm = leerEntero(mmT,1,12);
    cout << "Ingrese el dia: ";
    dd = leerEntero(ddT,1,meses[mm-1]);
    } else if(op == 2){
        //si se marca la segunda opcion de guarda la fecha del sistema
        time_t theTime = time(NULL);
        struct tm *aTime=localtime(&theTime);
        aa = (aTime->tm_year) + 1900;
        mm = aTime->tm_mon;
        dd = aTime->tm_mday;
    }
    //Se muestra la fecha original
    cout << endl << "La fecha es: " 
                           << setw(2) << setfill('0') << dd << "/"
                           << setw(2) << setfill('0') << mm << "/"
                           << aa << endl;
    //Se suma el dia
    sumarDia(&aa,&mm,&dd, &meses[mm-1]);
    //Se muestra la nueva fecha
    cout << endl << "El dia siguiente de esa fecha es: " 
                           << setw(2) << setfill('0') << dd << "/"
                           << setw(2) << setfill('0') << mm << "/"
                           << aa << endl;
    cout << endl;
    //Se pregunta si se quiere repetir la operacion.
    repetir = reiniciar(repetir);                      
    }while(repetir == true);
    return 0;
}
