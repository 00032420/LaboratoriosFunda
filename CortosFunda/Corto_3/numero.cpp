#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//Funcion que evalua la respuesta introducida, de ser incorrecta aumenta la cuenta de error
void intento(bool *correcto, int num, int respuesta, int *errores){
    *correcto = (respuesta == num)? true: false;
    if(*correcto == false) *errores+=1; 
}

//Funcion que muestra pistas para el usuario, dependiendo de el numero de errores que tenga.
void pistas(int num, int respuesta, int *errores){
    string pista = "Otra pista: El numero secreto es ";
    string paridad = (num%2 == 0)? "par.": "impar.";
    string r50 = (num >= 50)? " mayor o igual que 50.": " menor que 50.";
    string relacion = (num > respuesta)? "El numero secreto es mayor!": 
                      (num < respuesta)? "El numero secreto es menor": 
                      "Has adivinado el numero!";

    string primo = "primo", divs = "";
    for(int i = 2; i < num; i++){
        if (num%i == 0) {primo = "divisible entre "; divs += to_string(i) + "...";};
    }

    cout << relacion << endl;
    if(num != respuesta){
        switch (*errores){
        //Al primer error se dice la paridad
        case 1:
            cout << pista << paridad << endl;
            cout << "Intentos restantes : " << 5 - *errores << endl;
            break;

        case 2:
            cout << "Intentos restantes : " << 5 - *errores << endl;
            break;
        //al tercero su relacion con el 50
        case 3:
            cout << pista << r50 << endl;
            cout << "Intentos restantes : " << 5 - *errores << endl;
            break;

        //Para la ultima oportunidad se dicen los divisores o si es primo
        case 4:
            cout << "Ultima oportunidad: " << pista << primo << divs << endl;
            cout << "Intentos restantes : " << 5 - *errores << endl;
            break;
    
        default:
            cout << "Se te han acabado las oportunidades :(" << endl;
            cout << "El numero magico era " << num << endl;
            break;
        }
    }
}

//Función para repetir el juego.
bool reiniciar(bool repetir){
    cout << endl << "Desea jugar de nuevo? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayuscula o minuscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;  
}

//Funcion que verifica que se introduzca un numero y en el rango valido
void leerNumero(int *num, string indicaciones){
    while(cin.fail() || !(*num>=0 && *num <= 100)){
    cout << indicaciones;
    cin >> *num; 
    cin.clear(); 
    cin.ignore();}
}

int main(){
    //Valor de repetición, si es verdadero se repite el juego
    bool repetir;
    do{
    //Se calcula un numero al azar entre el 1 y el 100, utilizando una semilla en 
    //función del tiempo para que cada ejecución cuente con un numero nuevo
    srand(time(0));
    int numero = rand()%100 + 1;
    //Se definen otras funciones necesarias y se muestran indicaciones
    int errores = 0;
    bool correcto = false;
    cout << "Ingrese el numero 0 en cualquier momento para terminar el juego." << endl; 
    while (correcto != true && errores <5)
    {   cout << endl;
        //Se solicita la introduccion del numero
        int respuesta = -1;
        leerNumero(&respuesta, "Ingrese un numero del 1 al 100: ");
        //Si se ingresa el 0 se rompe el bucle y termina el juego
        if(respuesta == 0) break;
        cout << endl;
        //se evalua la respuesta y se muestran las pistas
        intento(&correcto, numero, respuesta, &errores);
        pistas(numero, respuesta, &errores);
    }
    cout << endl;
    //Se pregunta si se quiere repetir el juego.
    repetir = reiniciar(repetir);
    }while(repetir == true);
    cout << "Gracias por jugar." << endl;
    return 0;
}