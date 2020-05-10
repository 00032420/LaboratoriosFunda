#include <iostream>
#include <string> //Para string a float y validacion de datos
#include <cstdlib> 
#include <cmath> // para Pi y pow()
#include <iomanip> //Para std__setpresicion

using namespace std;

//Se verifica que el numero sea valido
float leer(string numero){ //Se pone como argumento el string de la entrada
    //Si la entrada contiene algun simbolo no admitido o fuera de rango, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890.") != string::npos){
        //Se muestra la advertencia
        cout << endl << "Numero invalido" << endl;
        if(atof(numero.c_str()) < 0){ //si el numero ingresado es negativo, también se advierte
            cout << "El radio de un circulo no puede ser negativo." << endl;
        }
        //Se solicita nuevo numero
        cout << "Por favor intente de nuevo. " << endl << endl;
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
        cout << "Ingrese el radio del circulo: ";
    }
    cout << endl;
    //Si se introdujo un numero valido, se devuelve convertido a float. 
    return atof(numero.c_str());
}

//Funcion para reiniciar las operaciones
bool reiniciar(bool repetir){
    cout << "Desea repetir la operacion? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin  >> rep;
    cout << endl;
    //Si se introdujo una S mayuscula o minuscula, devuelve verdadero, sino falso.
    return rep == "s" || rep == "S" ? true : false;
}

void area(double radio){
    //Se define el area en funcion del radio
    float a = M_PI * (pow(radio,2));
    //Se muestra el resultado, en modo fixed y dos decimales.
    cout << "El area del circulo es " << std::fixed << std::setprecision(2) << a << endl;  
}

//Se define el perimetro en funcion del radio
void perimetro(double radio){
    float p = 2 * M_PI * radio;
    cout << "El perimetro del circulo es " << std::fixed << std::setprecision(2) << p << endl;   
}

int main(){
    //Se define la variable tipo string donde se introducirá el numero, y 
    string radio;
    //Se definen las variables en donde se almacenara e radio y los calculos
    float r;
    //Valor de repetición, si es verdadero el programa se reinicia para hacer las operaciones de nuevo.
    bool repetir; 
    
    do{
        //Se solicita la entrada del radio 
        cout << "Ingrese el radio del circulo: ";
        //Se verifica y convierte el radio, y a la vez se guarda en la variable numerica
        r = leer(radio);

        //Se evaluan las funciones en con respecto al radio, y se guardan en sus respectivas variables
        perimetro(r);
        area(r); 
        cout << endl;

        //Se pregunta si se quiere repetir la operacion 
        repetir = reiniciar(repetir);

    } while(repetir == true);

    return 0;
}