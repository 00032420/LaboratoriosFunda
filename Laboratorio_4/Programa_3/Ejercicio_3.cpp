#include <iostream>
#include <string> //Para la manipulación de strings.

using namespace std;

//Función que verifica que se haya introducido un numero válido.
long double leerEntero(string numero){ //Se pone como argumento el string del numero

    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-.") != string::npos){

        //Se advierte el error
        cout << "Numero invalido." << endl << endl;
        cout << "Por favor intente de nuevo: ";

        //Se borra la entrada anterior 
        cin.clear();

        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return atof(numero.c_str() );
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

int main(){
    //Se declaran las variables necesarias
    string numTxt, estado;
    long double num;
    bool repetir; 

    do{
        //Se solicita y verifica el numero
        cout << "Ingrese un numero: ";
        num = leerEntero(numTxt);

        //Se verifica el estado del numero respecto a 0
        estado = (num > 0) ? "positivo": (num < 0)? "negativo": "0";
        //Se muestra el resultado
        (num != 0)? cout << endl << "El numero " << num << " es " << estado << "." << endl:
                    cout << endl << "El numero es " << estado << "." << endl;
        //Se pregunta si se desea repetir la operacion
        repetir = reiniciar(repetir);
    }while(repetir == true);

    return 0;
}