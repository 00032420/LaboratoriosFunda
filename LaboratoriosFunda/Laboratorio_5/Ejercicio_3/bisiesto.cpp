#include <iostream>
using namespace std;

//Funcion que verifica que se introduzca un numero y en el rango valido
void leerNumero(int *num, string indicaciones){
    while(cin.fail() || !(*num>=0)){
    cout << indicaciones;
    cin >> *num; 
    cin.clear(); 
    cin.ignore();}
}

//Funcion que verifica si un año es bisiesto
bool bisiesto(int year){
    return (year%400 == 0 || (year%4 == 0 && !(year%100 == 0)))? true:false;
}

//Función para repetir la operacion
bool reiniciar(bool repetir){
    cout << endl << "Desea ingresar otro a\244o? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayuscula o minuscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;  
}

int main(){
    //Valor de repetición, si es verdadero se repite la operacion
    bool repetir;
    do{
    int year = -1;
    leerNumero(&year, "Ingrese el a\244o: ");
    string b = ((bisiesto(year)==true)? " si ": " no ");
    //Se relaciona el año introducido con el año actual
    string r2020 = (year < 2020)? "fue ": (year == 2020)? "es ": "va a ser ";
    cout << "El a\244o " << year << b << r2020 << "bisiesto.";
    cout << endl;
    //Se pregunta si se quiere repetir la operacion
    repetir = reiniciar(repetir);
    }while(repetir == true);
    return 0;
}