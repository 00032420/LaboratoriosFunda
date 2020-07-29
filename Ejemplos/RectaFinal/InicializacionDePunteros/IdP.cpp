#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = NULL;
    char respuesta = 'n';
    cout << p << endl;

    cout << "Inicializar un puntero" << endl << endl;

    cout << "Desea que p apunte a la variable a [s/n]?";
    cin >> respuesta;

    if(respuesta == 's')
        p = &a;
    
    if(p != NULL){
        cout << "El puntero esta apuntando a la variable" << endl;
        cout << "En la direccion " << p << endl;
        cout << "Direccion de a:" << &a;
    } else 
        cout << "El puntero está apuntando a NULL";
    
    cout << endl;
    return 0;
}