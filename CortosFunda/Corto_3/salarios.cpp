#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip> //Para mostrar dos decimales.
using namespace std;

//Se definen las funciones que calculan el salario total y el real
float salarioTotal(float horasNormales, float horasExtra){
    //Se define el pago por hora normal y extra
    float normal = 1.75, extra = 2.50;
    //Se devuelve el salario total ()
    return (horasNormales*normal)+(horasExtra*extra);
}

float salarioReal(float salarioTotal){
    //Se definen los descuentos
    float seguro = 4.00/100, afp = 6.25/100, renta = 10.00/100;
    //Se calcula el descuento total
    float descuento = (salarioTotal*seguro) + (salarioTotal*afp);
    if(salarioTotal > 500) descuento+=(salarioTotal*renta);
    //Se devuelve el salario con el descuento aplicado
    return salarioTotal - descuento;
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
//Funcion que verifica que se introduzca un numero valido (no negativo y no letra)
//Para floats y enteros
void leerNumero(float *num, string indicaciones){
    while(cin.fail() || !(*num>0)){
    cout << indicaciones;
    cin >> *num; 
    cin.clear(); 
    cin.ignore();}
}
void leerNumero(int *num, string indicaciones){
    while(cin.fail() || !(*num>0)){
    cout << indicaciones;
    cin >> *num; 
    cin.clear(); 
    cin.ignore();}
}

int main(){
    //Valor de repetición, si este es verdadero se repite el programa.
    bool repetir;
    do{
    //Se solicita al usuario introducir el numero de empleados a calcular el sueldo
    int empleados = 0;
    leerNumero(&empleados, "Ingrese el numero de empleados : ");
    /*El bucle siguiente calcula y muestra, en función de los datos introducidos por el 
    usuario, el sueldo total y el sueldo real de cada empleado */
    for(int i = 0; i < empleados; i++){
        //Se definen las variables provisionales por cada empleado
        float hNormales = 0, hExtras = 0, sT, sR;
        cout << endl << "Empleado " << i+1 << ":" << endl;
        //Se solicita la introducción de horas trabajadas por cada empleado
        leerNumero(&hNormales, "Ingrese el numero de horas normales trabajadas: ");
        leerNumero(&hExtras, "Ingrese el numero de horas extras trabajadas: ");
        //Se calcula el salario en función de las horas trabajadas
        sT = salarioTotal(hNormales, hExtras);
        //Se calcula el salario real en función del salario total
        sR = salarioReal(sT);
        //Se muestran los resultados en pantalla, con dos decimales de precisión
        cout << endl;
        cout << setprecision(2) << fixed << "Salario Total: $" << sT << endl;
        cout << setprecision(2) << fixed << "Salario Real: $" << sR << endl;
    }
    cout << endl;
    //Se pregunta si se quiere repetir la operacion.
    repetir = reiniciar(repetir);
    }while(repetir == true);
    return 0;
}