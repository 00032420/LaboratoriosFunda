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
    string c, rLetras;
    char pLetra,uLetra;
    bool repetir;

   do{

    //Se solicita el ingreso de la palabra y se guarda en la variable
    cout << "Ingrese palabra: ";
    cin >> c;

    //Se itera cada caracter de la palabra para contarlos
    int l = 0;
    for(int i = 0; c[i]; i++) l++;
    
    //Se define la primera y la lutima letra
    pLetra = c[0];
    uLetra = c[l-1];

    //Se define su relacion
    rLetras = (tolower(pLetra) == tolower(uLetra)) ? " igual a": " diferente de";
    
    //Se muestran los resultados
    cout << endl << "La primera letra ('" << pLetra << "') de la palabra '" << c << "' es" << rLetras << " la ultima ('" << uLetra << "')" << ".";

    //Se pregunta si se desea repetir la operacion
    cout << endl;
    repetir = reiniciar(repetir);

   }while(repetir == true);
    return 0;
}