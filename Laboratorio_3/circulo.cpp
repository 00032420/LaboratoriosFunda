//Se incluyen librerías para la validación de datos, conversión de string a numeros y realización de operaciónes matemáticas
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//Se verifica que el numero sea valido
float convertir(string numero){ //Se pone como argumento el string de la entrada
    //Si la entrada contiene algun simbolo no admitido o fuera de rango, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890.") != string::npos){
        //Se muestra la advertencia
        cout << "Numero invalido" << endl;
        if(atof(numero.c_str()) < 0){ //si el numero ingresado es negativo, también se advierte
            cout << "El radio de un circulo no puede ser negativo." << endl;
        }
        //Se solicita nuevo numero
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //Si se introdujo un numero valido, se devuelve convertido a float. 
    return atof(numero.c_str());
}

//Se define el area en funcion del radio
double area(double radio){
    return M_PI * (pow(radio,2));
}

//Se define el perimetro en funcion del radio
double perimetro(double radio){
    return 2 * M_PI * radio;
}

int main(){
    //Se define la variable tipo string donde se introducirá el numero
    string radio;
    //Se definen las variables en donde se almacenara e radio y los calculos
    double r, p, a;
    
    //Se solicita la entrada del radio
    cout << "Ingrese el radio del circulo: ";
    //Se verifica y convierte el radio, y a la vez se guarda en la variable numerica
    r = convertir(radio);

    //Se evaluan las funciones en con respecto al radio, y se guardan en sus respectivas variables
    p = perimetro(r);
    a = area(r);

    //Se muestran los resultados
    cout << "El perimetro del circulo es " << p << endl;
    cout << "El area del circulo es " << a << endl;

    system("pause");
    return 0;
}