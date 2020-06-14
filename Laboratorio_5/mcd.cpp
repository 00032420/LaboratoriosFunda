#include <iostream>
#include <string>
using namespace std;

int mcd(int a, int b){
    //se determina el numero mayor y el menor
    if(a == 0){
        return b;
    } else if (b == 0)
    {
        return a;
    } else if(a == 0 && b == 0){
        return 0;
    } else {
        int M = (a>b)? a: b; 
    int m = (a<b)? a: b;
    int residuo;
    do{
        //Se calcula el residuo del mayor entre el menor
        residuo = M%m;
        if(residuo != 0){
            //Si el residuo no es cero, se le asigna el valor del menor al mayor
            // y el valor del residuo se le asigna al menor, y se vuelve a dividir.
            M = m;
            m = residuo;}
        } while (residuo != 0);
    return m;
    }
}

int leerEntero(string numero){ //Se pone como argumento el string del numero
    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-") != string::npos){
        //Se advierte el error
        cout << "Numero invalido." << endl << endl;
        cout << "Por favor intente de nuevo: ";
        //Se borra la entrada anterior 
        cin.clear();
        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }
    //En caso de haber introducido un número válido, se devuelve convertido a float, pero solo se toma la parte entera.
    return (int) atof(numero.c_str() );
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
    do{
    string numAtxt, numBtxt;
    int numA,numB;
    //se solicitan, verifican y guardan los datos
    cout << "Introduzca el primer numero: ";
    numA = leerEntero(numAtxt);
    cout << "Introduzca el segundo numero: ";
    numB = leerEntero(numBtxt);
    //Se calcula y muestra el maximo comun divisor
    cout << "El MCD es " << mcd(numA,numB) << endl;
    //En caso de que los numeros sean primos entre si, se muestra.
    if(mcd(numA,numB) == 1) cout << "Los numeros son primos entre si." << endl;
    cout << endl;
    //Se pregunta si se quiere repetir la operacion.
    repetir = reiniciar(repetir);
    } while(repetir == true);
    return 0;
}