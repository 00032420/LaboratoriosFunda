#include <iostream>
#include <string> //Para la manipulación de strings.

using namespace std;

//Función que verifica que se haya introducido un entero válido.
int leerEntero(string numero){ //Se pone como argumento el string del numero

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

    //En caso de haber introducido un número válido, se devuelve convertido a float.
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

void divisores(int n){

    char mm = 241;

    switch (n)
    {
    case 0:
        cout << "El 0 tiene infinitos divisores." << endl;
        break;
    
    case 1:
        cout << "El 1 tiene un unico divisor, que es el mismo." << endl;
        break;

    default:

        cout << endl << "Los divisores de " << n << " son: ";
    for(int i = 1; i <=abs(n);  i++){
        if(abs(n)%i == 0){
            (i != n)?
            cout << mm << i << ", "
            :
            cout << mm << i << ".";
            }
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
    bool repetir;
    string num1Txt,num2Txt;
    int num1,num2;
    
    do{

    cout << "Ingrese el primer entero: ";
    num1 = leerEntero(num1Txt);
    cout << "Ingrese el segundo entero: ";
    num2 = leerEntero(num1Txt);
    cout << endl;

    esDivisible(num1,num2);
    divisores(num1);

    cout << endl;
    repetir = reiniciar(repetir);

    } while(repetir == true);
     
    return 0;
}