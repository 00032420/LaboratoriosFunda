#include <iostream>
#include <string> //Para string a float y validacion de datos
#include <cstdlib> 
#include <cmath> // para Pi y pow()
#include <iomanip> //Para std__setpresicion


using namespace std;

//Se verifica que el numero sea valido
float leer(string numero){ //Se pone como argumento el string de la entrada
    //Si la entrada contiene algun simbolo no admitido o fuera de rango, se hace lo siguiente:
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

bool reiniciar(bool repetir){
    cout << "Desea repetir la operacion? [S/N] ";
    string rep;
        cin >> rep;

            if(rep == "s" || rep == "S"){
            //Si se introduce una s, mayuscula o minuscula, el valor repeteición queda verdadero y se repite el ciclo
            cout << endl;
            return true;
            }
            //si no se introduce una s, el valor repeticion queda falso y se termina el programa. 
            return false;         
}



void d_positivo(float a, float b, float c, float dis){
    float r1 = ((-b)+sqrt(dis))/(2*a);
    float r2 = ((-b)-sqrt(dis))/(2*a);
    cout << "X1: " << std::fixed << std::setprecision(2) << r1 << endl;
    cout << "X2: " << std::fixed << std::setprecision(2) << r2 << endl;
}

void d_cero(float a, float b){
    float x = (-b)/(2*a);
    cout << "X: " << std::fixed << std::setprecision(2) << x << endl;
}

void d_negativo(float a, float b, float c, float dis){
    float parte_real = ( (-b)/(2*a));
    float parte_img = ( sqrt( -dis)/(2*a));

    cout << "La ecuacion no tiene solucion en los numeros reales." << endl;
    cout << "Pero si en los complejos:" << endl << endl;

    if(parte_img > 0){

        cout << "X1: " << parte_real << " + " << std::fixed << std::setprecision(2) << parte_img <<  "i" << endl;
        cout << "X2: " << parte_real << " - " << std::fixed << std::setprecision(2) << parte_img <<  "i" << endl;;
    } else {
        cout << "X1: " << parte_real << std::fixed << std::setprecision(2) << " - " << (-parte_img) <<  "i" << endl;
        cout << "X2: " << parte_real << " + " << std::fixed << std::setprecision(2) << (-parte_img) <<  "i" << endl;;

    }
}


int main(){
    //Se define la variable tipo string donde se introducirá el numero, y otro en caso de no tener solución 
    string x2, x1, x0;
    
    //Se definen las variables en donde se almacenara e radio y los calculos
    float a, b, c, d;
    bool repetir; //Valor de repetición, si es verdadero el programa se reinicia para hacer las operaciones de nuevo.
    
    do{
        //Se solicita la entrada del radio 
        cout << "Ingrese A: ";
        //Se verifica y convierte el radio, y a la vez se guarda en la variable numerica
        a = leer(x2);

        cout << "Ingrese B: ";
        b = leer(x1);

        cout << "Ingrese C: ";
        c = leer(x0);

        //Se guarda el valor del discriminante 
        d = (b*b)-4*a*c;

        if(d >0){
            d_positivo(a,b,c,d);
        } else if( d == 0){
            d_cero(a,b);  
        } else {  
            d_negativo(a,b,c,d);
        }
        
        cout << endl;

        //se pregunta si se quiere relizar la operación de nuevo
        repetir = reiniciar(repetir);
        
    } while(repetir == true);

    return 0;
}