#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>
#include <sstream>

using namespace std;

//Funcion que verifica que el precio introducido sea valido
float leerPrecio(string numero){
    //Mientras se introduzca un numero y este incluya un caracter no admitido, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890.") != string::npos){
        //Se muestra la advertencia
        cout << endl << "Numero invalido." << endl;
        if(atof(numero.c_str()) < 0){ //Si se introdujo un numero valido, pero negativo, se advierte
            cout  << "El precio del producto no puede ser negativo." << endl;
        }
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
        //se solicita introducir el valor nuevamente
        cout << "Por favor intente de nuevo." << endl << endl;
        cout << "Ingrese el precio de producto: $";
    }
    //Si se introdujo un numero valido, se devuelve convertido a float
    return atof(numero.c_str());
}

//Funcion que verifica que la cantidad instroducida sea valida
float leerCantidad(string numero){
    //Mientras se introduzca un numero y este incluya un caracter no admitido, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890") != string::npos){
        //Se muestra la advertencia
        cout << endl << "Numero invalido." << endl;
        if(atof(numero.c_str()) < 0){ //Si se introdujo un numero valido, pero negativo, se advierte
            cout  << "La cantidad de productos no puede ser negativa." << endl;
        }
        if(numero.find_first_of(".") != string::npos){
            cout << "La cantidad de productos debe ser un numero entero." << endl;
        }
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
        //se solicita introducir el valor nuevamente
        cout << "Por favor intente de nuevo." << endl << endl;
        cout << "Ingrese la cantidad: ";
    }
    cout << endl;
    //Si se introdujo un numero valido, se devuelve convertido a float
    return atof(numero.c_str());
}

int main(){

    //Se declaran las variables tipo string para la introduccion de datos
    string producto, txtPrecio, txtCantidad; 
    //Se declaran las variable snumericas para almacenar los datos
    float precio, totalProducto, cantidad, total;

    //Se solicita la entrada del producto
    cout << "Ingrese nombre del producto: ";
    //Para habilitar multiples palabras, se almacena la linea en su respectiva variable
    getline(cin, producto);

    //Se solicita el valor del precio y se guardará solo si es valido
    cout << "Ingrese precio del producto: $";
    precio = leerPrecio(txtPrecio);

    //Se solicita la cantidad y se guardará si es valida
    cout << "Ingrese la cantidad: ";
    cantidad = leerCantidad(txtCantidad);

    //Se calcula el monto total y se muestra en pantalla, modo fixed y dos decimales.
    totalProducto = precio*cantidad;
    cout << "El total en dicho producto es: $" << std::fixed << std::setprecision(2) << totalProducto << endl << endl;

    return 0;
}