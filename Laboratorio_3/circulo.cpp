#include <iostream>
#include <string> //Para string a float y validacion de datos
#include <cstdlib> 
#include <cmath> // para Pi y pow()
#include <iomanip> //Para std__setpresicion


using namespace std;

//Se verifica que el numero sea valido
float convertir(string numero){ //Se pone como argumento el string de la entrada
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

//Se define el area en funcion del radio
float area(double radio){
    return M_PI * (pow(radio,2));
}

//Se define el perimetro en funcion del radio
float perimetro(double radio){
    return 2 * M_PI * radio;
}

int main(){
    //Se define la variable tipo string donde se introducirá el numero, y 
    string radio, rep;
    //Se definen las variables en donde se almacenara e radio y los calculos
    float r, p, a;
    bool repetir; //Valor de repetición, si es verdadero el programa se reinicia para hacer las operaciones de nuevo.
    
    do{
        //Se solicita la entrada del radio 
        cout << "Ingrese el radio del circulo: ";
        //Se verifica y convierte el radio, y a la vez se guarda en la variable numerica
        r = convertir(radio);

        //Se evaluan las funciones en con respecto al radio, y se guardan en sus respectivas variables
        p = perimetro(r);
        a = area(r);
    
        //Se muestran los resultados, en fixed para evitar notacion cientifica y presicion de dos decimales
        cout << "El perimetro del circulo es " << std::fixed << std::setprecision(2) << p << endl;
        cout << "El area del circulo es " << std::fixed << std::setprecision(2) << a << endl;
        cout << endl;
        cout << "Desea repetir la operacion? [S/N] ";

        //se pregunta si se quiere relizar la operación de nuevo
        cin >> rep;

            if(rep == "s" || rep == "S"){
            //Si se introduce una s, mayuscula o minuscula, el valor repeteición queda verdadero y se repite el ciclo
            repetir = true;
            cout << endl;
            } else {
            //si no se introduce una s, el valor repeticion queda falso y se termina el programa. 
            repetir = false;
            }

    } while(repetir == true);

    return 0;
}