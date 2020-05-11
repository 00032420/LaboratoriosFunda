#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip>

using namespace std;

//Funcion que verifica que eel precio introducido sea valido
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
    cout << endl;
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
        if(numero.find_first_of(".") == string::npos){
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

bool reiniciar(bool repetir){
    cout << "Desea repetir la operacion? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin  >> rep;
    cout << endl;
    //Si se introdujo una S mayuscula o minuscula, devuelve verdadero, sino falso.
    return (rep == "s" || rep == "S") ? true : false;
}

void leerProducto(){
    string producto;
    getline(cin,producto);
    cin.clear();
    cin.ignore(123, '\n');
}

int main(){

    bool repetir;

    do{

    string producto, txtPrecio, txtCantidad; 
    float precio, totalProducto, cantidad, total;

    cout << "Ingrese nombre del producto: ";
    leerProducto();
    cout << "Ingrese precio del producto: $";
    precio = leerPrecio(txtPrecio);
    cout << "Ingrese la cantidad: ";
    cantidad = leerCantidad(txtCantidad);
    totalProducto = precio*cantidad;
    cout << "El total en dicho producto es: $" << std::fixed << std::setprecision(2) << totalProducto << endl;

    repetir = reiniciar(repetir);
    } while(repetir == true);

    return 0;
}