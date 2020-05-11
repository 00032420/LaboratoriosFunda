#include <iostream>
#include <string> //Para string a float y validacion de datos
#include <cstdlib> 
#include <cmath> // Para operaciones funciones matemáticas
#include <iomanip> //Para la presicion de decimales y modo fixed

using namespace std;

//Funcion que verifica que el numero introducido sea valido
float leer(string numero){ //Se pone como argumento el string del numero

    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-") != string::npos){

        //Se advierte el error
        cout << "Numero invalido." << endl << endl;
        cout << "Por favor intente de nuevo: ";

        //Se borra la entrada anterior 
        cin.clear();

        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //En caso de haber introducido un número válido, se devuelve convertido a float.
    return atof(numero.c_str() );
}

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
   //Se declaran variables tipo string para la entrada de numeros. 
    string num1 , num2, num3;
    //Se declaran enteros para luego almacenar los strings convertidos
    double a, b, c, promedio;
    //Se declara el valor de repeticion. Si este es verdadero, se repite la operacion
    bool repetir;
    
    do {
    //Se solicita el numero
    cout << "Ingrese el primer entero: "; 

    //Se evalúa la entrada, en caso de ser válida, se guardará como un entero en la variable indicada
    //De no ser así, se solicitará hasta que la entrada sea válida. 
    a = leer(num1);
    
    cout << "Ingrese el segundo entero: ";
    b = leer(num2);
   
    cout << "Ingrese el tercer entero: ";
    c = leer(num3);
    
    //Se promedian las cantidades y se almacenan en la variable
    promedio = (a+b+c)/3; 

    //Se muetra el resultado en modo fixed y dos decimales.
    cout << endl << "El promedio es " << std::fixed << std::setprecision(2) << promedio << endl;

    //Se pregunta si se desea repetir la operacion
    repetir = reiniciar(repetir);

    } while(repetir == true);

    return 0;
}