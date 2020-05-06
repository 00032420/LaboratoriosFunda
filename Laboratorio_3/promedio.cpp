#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

float convertir(string numero){
    while(cin >> numero && numero.find_first_not_of("1234567890.-") != string::npos){
        cout << "Numero invalido." << endl;
        cout << "Por favor intente de nuevo: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return atof(numero.c_str() );
}

int main(){
   
    string num1 , num2, num3;
    float a, b, c,promedio;
    bool valido = false;
    
    cout << "Ingrese el primer numero: "; 
    a = convertir(num1);
    
   
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    if(num2.find_first_not_of("1234567890.-") != string::npos){
        cout << "Numero invalido";
        return 0;
    }
    b = atof(num2.c_str());
   
    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    if(num3.find_first_not_of("1234567890.-") != string::npos){
        cout << "Numero invalido";
        return 0;
    }
    c = atof(num3.c_str());
    
    promedio = (a+b+c)/3; 
    cout << "El promedio es " << promedio << endl;

    
    return 0;
}