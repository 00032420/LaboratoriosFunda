#include <iostream>
#include <string>

using namespace std;

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

int main() {
    //Se definen las variables necesarias.
    string c, r10, paridad;
    bool repetir;

   do{

    //Se solicita el ingreso de la palabra y se guarda en la variable
    cout << "Ingrese palabra: ";
    cin >> c;

    //Se itera cada caracter de la palabra para contarlos
    int l = 0;
    for(int i = 0; c[i]; i++) l++;
    //Se determina su relación en cuanto al 10
    r10 = (l>10) ? " mas de":(l<10)? " menos de": "";
    //Se determina la paridad
    paridad = (l%2==0)? " par": " impar";
    //Se muestran los resultados.
    cout << endl << "La palabra '" << c << "' tiene" << r10 << " 10 caracteres y su longitud (" << l << ") es " << paridad << ".";

    //Se pregunta si se desea repetir la operacion
    cout << endl;
    repetir = reiniciar(repetir);

   }while(repetir == true);
    return 0;
}