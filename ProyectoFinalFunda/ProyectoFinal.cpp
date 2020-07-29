#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

const int longCad = 20;

struct costoPorArticulo{
    char nombreArticulo[longCad+1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

//Se definen los prototipos de las funciones requeridas
void leerDatos(costoPorArticulo[], int);
void calcularCosto(costoPorArticulo[], int);
void desplegarArreglo(costoPorArticulo[], int, string);
float costoTotal(costoPorArticulo[], int);
//Otras funciones
string crearArchivo();
void llenarFactura(costoPorArticulo[], int, string);
bool reiniciar(bool);
int validarEntero(string);
float validarFloat(string);

//Función principal
int main(){
//Valor de repetición, si este es verdadero el programa se repite.
    bool repetir;
 do{
    //Se crea el archivo de la factura y se obtiene el identificador.
    string id = crearArchivo();
    //Se declara la variable que contendrá la cantidad de artículos a ingresar
    int n;
    cout << endl << "Procesamiento de factura" << endl << endl;
    //Se solicita la cantidad de artículos
    cout << "Ingrese el numero de articulos: ";
    n = validarEntero(to_string(n));
    //Se limpia el teclado
    cin.ignore(100, '\n');
    //Se declara el arreglo de estructuras con la longitud ingresada
    costoPorArticulo listado[100];
    //Se llaman las funciones
    leerDatos(listado,n);
    calcularCosto(listado,n);
    desplegarArreglo(listado,n, id);
    llenarFactura(listado, n, id);
    //Se calcula y se muestra el precio total
    cout << endl <<  "Costo total: $";
    cout << fixed << setprecision(2) << costoTotal(listado, n) << endl << endl;
    //Se pregunta al usuario si se desea procesar otra factura.
    repetir = reiniciar(repetir);
 } while(repetir == true);

    return 0;
}

void leerDatos(costoPorArticulo listado[], int n){
    //Se declara una cadena donde se introducirá el texto
    string texto;
    cout << endl;
    cout << "Digite digite el nombre, la cantidad y el precio unitario de cada articulo: " << endl;
    //Se itera sobre cada estructura, solicitando los datos
    for(int i = 0; i < n; i++){
        cout << endl << "Nombre del articulo: ";
        getline(cin, texto, '\n');
        strncpy(listado[i].nombreArticulo, texto.c_str(), longCad);
        listado[i].nombreArticulo[longCad] = '\0';
        cout << "Cantidad: ";
        listado[i].cantidad = validarEntero(to_string(listado[i].cantidad));
        cout << "Precio: $";
        listado[i].precio = validarFloat(to_string(listado[i].precio));
        cin.ignore(100, '\n');
    }
}

void calcularCosto(costoPorArticulo listado[], int n){
    for(int i = 0; i < n; i++){
        //Se itera sobre cada estructura para calcular el costo total
        listado[i].costoPorArticulo = listado[i].cantidad * listado[i].precio;
    }
}

void desplegarArreglo(costoPorArticulo listado[], int n, string id){
    //Se itera sobre cada estructura mostrando cada dato en forma de factura
    cout << endl  << "Factura #" << id << endl << endl;
    cout  << setw(23) << left << "Nombre del articulo" 
          << setw(10) << right << "Cantidad"
          << setw(15) << right << "Precio" 
          << setw(15) << right << "Costo" << endl;
    for(int i = 0; i < 63; i++) cout << "-";
    cout << endl;

    for(int i = 0; i < n; i++){
        //Se usa un buffer de texto (como en los archivos) para darle formato al dinero
        stringstream costo, precio;
        costo << "$" << fixed << setprecision(2) << listado[i].costoPorArticulo;
        precio << "$" << fixed << setprecision(2) << listado[i].precio;
        //Se muestran las variables, espaciadas y alineadas
        cout << setw(23) << left << listado[i].nombreArticulo;
        cout << setw(10) << right << listado[i].cantidad;
        cout << setw(15) << right << precio.str();
        cout << setw(15) << right << costo.str() << endl;
        if(i != n-1) cout << endl; 
    }

    for(int i = 0; i < 63; i++) cout << "-";
}


float costoTotal(costoPorArticulo listado[], int n){
    float total = 0.00;
    //Se itera sobre cada estructura para sumar el costo a la variable total
    for(int i = 0; i < n; i++)
        total += listado[i].costoPorArticulo;
    return total;
}

//Función para crear nuevo archivo de factura
string crearArchivo(){
//Se declara una bandera, un puntero a ella, un indice y una cadena para el numero de ticket
    bool archivoExiste = false;
    bool *pAr = &archivoExiste;
    int i = 1;
    string idTxt;
    while(archivoExiste == false){
        ifstream archivo;
        //Se inicializa el ticket como un arreglo de 5 ceros, siendo los últimos reemplazados por el índice
        idTxt = string((5 - to_string(i).length()),'0').append(to_string(i));
        //Se verifica si el archivo con el numero existe
        archivo.open("Facturas/Factura" +  idTxt + ".txt");
        if(!archivo){ //Si no existe, este se crea
            ofstream factura("Facturas/Factura" + idTxt +  ".txt", ios::app);
            *pAr = true;
        } else{//Si el archivo existe, el indice aumenta y la bandera se marca como falsa
            i = i+1;
            *pAr = false;
        }
    }
    //Se retorna el numero, para escribir sobre el archivo posteriormente
    return idTxt;
}

//La siguiente función opera exactamente igual que la de mostrarArreglo, pero en archivo
void llenarFactura(costoPorArticulo listado[], int n, string id){
    //Se abre el documento correspondiente al id
    ofstream factura("Facturas/Factura" +  id +  ".txt", ios::app);
    //Se itera sobre cada estructura grabando cada dato
    factura << endl  << "Factura #" << id << endl << endl;
    factura  << setw(23) << left << "Nombre del articulo" 
             << setw(10) << right << "Cantidad"
             << setw(15) << right << "Precio" 
             << setw(15) << right << "Costo" << endl;
    for(int i = 0; i < 63; i++) factura << "-";
    factura << endl;

    for(int i = 0; i < n; i++){
        //Se usa un buffer de texto (como en los archivos) para darle formato al dinero
        stringstream costo, precio;
        costo << "$" << fixed << setprecision(2) << listado[i].costoPorArticulo;
        precio << "$" << fixed << setprecision(2) << listado[i].precio;
        
        factura << setw(23) << left << listado[i].nombreArticulo;
        factura << setw(10) << right << listado[i].cantidad;
        factura  << right  << setw(15) << precio.str();
        factura  << right  << setw(15) << costo.str() << endl;
        if(i != n-1) factura << endl;
    }
    for(int i = 0; i < 63; i++) factura << "-";
    factura << endl << "Costo Total: $";
    factura << fixed << setprecision(2) << costoTotal(listado, n) << endl;
}

//Función para repetir la operación.
bool reiniciar(bool repetir){
    cout << endl << "Desea procesar otra factura? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayúscula o minúscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;  
}

//Función para verificar que el entero introducido sea válido
int validarEntero(string numero){ //Se pone como argumento el string del numero
    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890") != string::npos ){
        //Se advierte el error
        cout << "Entero invalido." << endl << endl;
        if(atof(numero.c_str()) < 0) //si el numero ingresado es negativo, también se advierte
            cout << "La cantidad no puede ser negativa." << endl;
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior 
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(100, '\n');
    }
    //En caso de haber introducido un número válido, se devuelve la parte entera.
    return (int) atof(numero.c_str() );
}

float validarFloat(string numero){ //Se pone como argumento el string de la entrada
    //Si la entrada contiene algún símbolo no admitido o fuera de rango, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890.") != string::npos){
        //Se muestra la advertencia
        cout << endl << "Numero invalido" << endl;
        if(atof(numero.c_str()) < 0) //si el numero ingresado es negativo, también se advierte
            cout << "El precio no puede ser un valor negativo." << endl;
        //Se solicita nuevo numero
        cout << "Por favor intente de nuevo. " << endl << endl;
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(100, '\n');
        cout << "Ingrese el precio: ";
    }
    cout << endl;
    //Si se introdujo un numero valido, se devuelve convertido a float. 
    return atof(numero.c_str());
}