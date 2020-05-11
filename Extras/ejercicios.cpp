#include <iostream>
using namespace std;

int main(){
   
    int a = 0; //Declaración de la variable a
    
    /* Declaración de dos variables de tipo entero y asignandoles un valor. */

    int num1 = 6;
    int num2 = 3;

    //Declaración de variables donde almacenaremos los resultados de las operaciones

    int suma = num1 + num2;
    int resta = num1 - num2;
    int multi = num1 * num2;
    int div = num1/num2;
    int mod = num1%num2;

    /* Usamos cin seguida de >> y luego el nombre de la variable a ingresar
    en caso de pedir más, ingresamos >> de nuevo, seguido del nombre de la siguiente variable. */

    int numa, numb;

    cin >> numa >> numb;
    int suma2 = numa+numb; 
    cout << suma2;

    //Concatenación

    string concatenar;

    string string1 = "Hola ";
    string string2 = "mundo2";

    concatenar = string1+string2;
    cout << concatenar;

     return 0;
}