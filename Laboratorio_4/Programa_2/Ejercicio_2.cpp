#include <iostream>
#include <string> //Para la manipulación de strings.

using namespace std;

//Función que verifica que se haya introducido un entero válido.
long int leerEntero(string numero){ //Se pone como argumento el string del numero

    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-") != string::npos){

        //Se advierte el error
        cout << "Entero invalido." << endl << endl;
        cout << "Por favor intente de nuevo: ";

        //Se borra la entrada anterior 
        cin.clear();

        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return (int) atof(numero.c_str() );
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
    string numTxt, paridad;
    int num;
    bool repetir; 

    do{
        //Se solicita y verifica el numero
        cout << "Ingrese un entero: ";
        num = leerEntero(numTxt);

        //Se verifica la paridad
        paridad = (num%2 == 0) ? "par" : "impar";
        //Se muestra el resultado
        cout << endl << "El numero " << num << " es " << paridad << "." << endl;
        //Se pregunta si se desea repetir la operacion
        repetir = reiniciar(repetir);
    }while(repetir == true);

    return 0;
}