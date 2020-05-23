#include <iostream>
#include <string> //Para la manipulación de strings.

using namespace std;

//Función que verifica que se haya introducido un entero válido.
long int leerEntero(string numero){ //Se pone como argumento el string del numero

    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-") != string::npos){

        //Se advierte el error
        cout << "Entero invalido." << endl << endl;
        cout << "Por favor intente de nuevo: ";

        //Se borra la entrada anterior 
        cin.clear();

        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return (int) atof(numero.c_str() );
}


void esDivisible(int n1,int n2){
    //Se verifica que el denominador no sea 0
    if (n2 == 0) {    
        cout << "Resultado indeterminado. El denominador no puede ser 0." << endl;
        return;
    } else { //En caso de ser diferente de 0, se evaluan los casos.
                (n1%n2 == 0)? 
                cout << n1 << " es divisible entre " << n2 << "." << endl :
                cout << n1 << " no es divisible entre " << n2 << "." << endl;  
            }
}

//Función que imprime los divisores de un numero
void divisores(int n){
    //Se define el signo +/-

    char mm = 241;

    //Se evaluan los casos
    (n == 0)?
        cout << "El 0 tiene infinitos divisores." << endl:
        
        cout << endl << "Los divisores de " << n << " son: ";
            //Se itera desde el 1 hasta el valor absoluto del numero
            for(int i = 1; i <=abs(n);  i++){
            //En cada iteracion se verifica que el modulo sea 0
            if(abs(n)%i == 0){
              //Si el modulo es 0:
                (i != n)?
                 //Se imprime cada divisor, son el signo +/- separado por una coma
                 cout << mm << i << ", "
                 :
                 //Se imprime el último seguido de un punto
                  cout << mm << i << ".";
                 }
            }
    }

//Función para repetir la operación.
bool reiniciar(bool repetir){
    cout << endl << "Desea repetir la operacion? [S/N] ";
    //Se crea la variable para almacenar la respuesta del usuario
    string rep;
    //Se introduce la respuesta
    cin >> rep;
    cout << endl;
    //Si se introduce s, ya sea mayuscula o minuscula, devuelve verdadero, caso contrario devuelve falso.
    return rep == "s" || rep == "S" ? true : false;  
}

int main(){
    //Se definen las variables
    bool repetir;
    string num1Txt,num2Txt;
    long int num1,num2;
    

    do{
        //Se ingresan y verifican los numeros
    cout << "Ingrese el primer entero: ";
    num1 = leerEntero(num1Txt);
    cout << "Ingrese el segundo entero: ";
    num2 = leerEntero(num1Txt);
    cout << endl;

    //Se ejecutan las funciones
    esDivisible(num1,num2);
    divisores(num1);

    cout << endl;
    //Se pregunta si se quiere repetir la operacion.
    repetir = reiniciar(repetir);

    } while(repetir == true);
     
    return 0;
}