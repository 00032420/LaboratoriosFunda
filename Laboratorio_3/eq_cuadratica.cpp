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



float rmas(float a, float b, float c, float dis){
    return ((-b)+sqrt(dis))/(2*a);
}

float rmenos(float a, float b, float c, float dis){
    return ((-b)-sqrt(dis))/(2*a);
}

float rcero(float a, float b){
    return (-b)/(2*a);
}

void r_comp(float a, float b, float c, float dis){
    float parte_real = ( (-b)/(2*a));
    float parte_img = ( sqrt( -dis)/(2*a));
    
    cout << "X1: " << parte_real << " + " << parte_img <<  "i" << endl;;
    cout << "X2: " << parte_real << " - " << parte_img <<  "i" << endl;;
}


int main(){
    //Se define la variable tipo string donde se introducirá el numero, y otro en caso de no tener solución 
    string x2, x1, x0,rep, img1, img2;
    
    //Se definen las variables en donde se almacenara e radio y los calculos
    float a, b, c, d, r1, r2;
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
            r1 = rmas(a,b,c,d);
            r2 = rmenos(a,b,c,d);
            cout << "X1: " << std::fixed << std::setprecision(2) << r1 << endl;
            cout << "X2: " << std::fixed << std::setprecision(2) << r2 << endl;
        } else if( d == 0){
            r1 = rcero(a,b);
            cout << "X: " << std::fixed << std::setprecision(2) << r1 << endl;
        } else
        {
            
            cout << "La ecuacion no tiene solucion en los numeros reales." << endl;
            cout << "Pero si en los complejos :v" << endl << endl;
            r_comp(a,b,c,d);
        }
        
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