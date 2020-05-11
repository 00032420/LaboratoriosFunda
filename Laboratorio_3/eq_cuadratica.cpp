#include <iostream>
#include <string> //Para string a float y validacion de datos
#include <cstdlib> 
#include <cmath> // Para operaciones funciones matemáticas
#include <iomanip> //Para la presicion de decimales y modo fixed

using namespace std;

//Función que verifica que el numero sea valido
float leer(string numero){ //Se pone como argumento el string de la entrada
    //Si la entrada contiene algun simbolo no admitido, se hace lo siguiente:
    while(cin >> numero && numero.find_first_not_of("1234567890.-") != string::npos){
        //Se muestra la advertencia
        cout << endl << "Numero invalido" << endl;
        //Se solicita nuevo numero
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }
    cout << endl;
    //Si se introdujo un numero valido, se devuelve convertido a float. 
    return atof(numero.c_str());
}

//Función para reiniciar el programa. El argumento es el valor de repeticion
bool reiniciar(bool repetir){
    cout << "Desea repetir la operacion? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayuscula o minuscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;       
}

//Se definen las respuestas en caso de que el discriminante sea positivo
void d_positivo(float a, float b, float c, float dis){

    //Se calculan las dos respuestas
    float r1 = ((-b)+sqrt(dis))/(2*a);
    float r2 = ((-b)-sqrt(dis))/(2*a);
    //Se muestran las dos respuestas, en modo fixed y con dos decimales
    cout << "X1: " << std::fixed << std::setprecision(2) << r1 << endl;
    cout << "X2: " << std::fixed << std::setprecision(2) << r2 << endl;
}

//Se define la respuesta si el discriminante es igual a cero
void d_cero(float a, float b){
    //Se calcula la solucion. Como el discriminante es cero, la ecuacion solo tiene una.
    float x = (-b)/(2*a);
    //Se muestra la solucion, en modo fixed y con dos decimales
    cout << "X: " << std::fixed << std::setprecision(2) << x << endl;
}

//Si el discriminante es menor a cero, la ecuacion no tiene soloucion en el campo de los reales
//Pero si en los complejos. (Es opcional, pero quería experimentar.)
void d_negativo(float a, float b, float c, float dis){
    //Se calcula la parte real y la parte imaginaria.
    float parte_real = ( (-b)/(2*a));
    float parte_img = ( sqrt( -dis)/(2*a));

    cout << "La ecuacion no tiene solucion en los numeros reales." << endl;
    cout << "Pero si en los complejos:" << endl << endl;

    /*Se estructuran la soluciones en caso de que la parte imaginaria sea positiva. 
        X1 = a + bi y x2 = a - bi
        y se muestran en modo fixed y dos decimales.*/ 
    if(parte_img > 0){
        cout << "X1: " << parte_real << " + " << std::fixed << std::setprecision(2) << parte_img <<  "i" << endl;
        cout << "X2: " << parte_real << " - " << std::fixed << std::setprecision(2) << parte_img <<  "i" << endl;;
    } else { 
        /* Se estructuran la solluciónes en case de que la parte imaginaria sea negativa.
        x1 = a + (-bi) = a - bi y x2 = a - (-bi) = a + bi */
        cout << "X1: " << parte_real << std::fixed << std::setprecision(2) << " - " << (-parte_img) <<  "i" << endl;
        cout << "X2: " << parte_real << " + " << std::fixed << std::setprecision(2) << (-parte_img) <<  "i" << endl;;
    }
}


int main(){
    //Se define las variables tipo string donde se introducirán los numeros. 
    string x2, x1, x0;
    
    //Se definen las variables en donde se almacenara los valores numericos y el discriminante.
    float a, b, c, d;

    //Valor de repetición, si es verdadero el programa se reinicia para hacer las operaciones de nuevo.
    bool repetir; 
    
    do{
        //Se solicita la entrada del respectivo coeficiente
        cout << "Ingrese el valor de 'a' : ";
        //Se verifica y convierte a valor numerico.
        a = leer(x2);

        cout << "Ingrese el valor de 'b' : ";
        b = leer(x1);

        cout << "Ingrese el valor de 'c' : ";
        c = leer(x0);

        //Se guarda el valor del discriminante 
        d = (b*b)-4*a*c;

        //Se evalúa el discriminante y se ejecuta la función respectiva a su caso
        (d > 0) ? d_positivo(a,b,c,d): (d == 0) ? d_cero(a,b) : d_negativo(a,b,c,d);
        cout << endl;

        //Se pregunta si se quiere repetir la operacion. 
        repetir = reiniciar(repetir);
        
    } while(repetir == true);

    return 0;
}