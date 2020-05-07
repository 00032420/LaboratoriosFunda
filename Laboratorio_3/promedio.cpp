#include <iostream>
//Se incluyen librerias para la validación de datos.
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//La siguiente función verifica que se haya introducido un número válido y lo convierte de string a float

float convertir(string numero){ //Se pone como argumento el string del numero

    /*Mientras se introduzca un número
        y alguno de sus caracteres no coincida con los permitidos:  */
    while(cin >> numero && numero.find_first_not_of("1234567890-") != string::npos){

        //Se advierte el error
        cout << "Numero invalido." << endl;
        cout << "Por favor intente de nuevo: ";

        //Se borra la entrada anterior 
        cin.clear();

        //Se descarta la entrada anterior
        cin.ignore(123, '\n');
    }

    //En caso de haber introducido un número válido, se devuelve convertido a float.
    return atof(numero.c_str() );
}

int main(){
   //Se declaran variables tipo string para la entrada de numeros. 
    string num1 , num2, num3;
    //Se declaran enteros para luego almacenar los strings convertidos y el promedio
    double a, b, c, promedio;
    
    
    //Se solicita el numero
    cout << "Ingrese el primer numero: "; 

    //Se evalúa la entrada, en caso de ser válida, se guardará como un entero en la variable indicada
    //De no ser así, se solicitará hasta que la entrada sea válida. 
    a = convertir(num1);
    
   
    cout << "Ingrese el segundo numero: ";
    b = convertir(num2);
   
    cout << "Ingrese el tercer numero: ";
    c = convertir(num3);
    
    //Se promedian las cantidades y se almacenan en la variable
    promedio = round((a+b+c)/3); 

    //Se muetra el resultado. 
    cout << "El promedio es " << promedio << endl;

    system("pause");
    return 0;
}

/*
Fuentes:

https://stackoverflow.com/questions/4271315/c-how-to-check-an-input-float-variable-for-valid-input
https://www.youtube.com/watch?v=m2P5A4nR51g

*/