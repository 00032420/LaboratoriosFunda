#include <iostream>
#include <cctype>
using namespace std;

int main(){
    double num1, num2, num3, promedio; //Declarando variables 
    
    
    
    cout << "Ingrese el primer numero: "; 
    cin >> num1; 
   
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
   
    cout << "Ingrese el tercer numero: ";
    cin >> num3;
    
    promedio = (num1+num2+num3)/3; 
    cout << "El promedio es " << promedio << endl;

    
    return 0;
}