#include <iostream>
#include <string>

using namespace std; 

int main(){
    //Se definen las variables para el menu
    string menu[5][2] { "Pais             ", " Iva " ,
                        "El Salvador ", " 13% ",
                        "Guatemala   ", "  9% ",
                        "Honduras    ", " 15% ",
                        "Espana      ", " 20% " }; 

    int item[5]; 
    int pais;
    

    //Se muestra el menu por medio de iteraciones de sus celdas
    cout << "Menu: " << endl << "========================" << endl;
    for(int f = 0; f < 5; f++){
        item[f] = f;
        if(f != 0) cout << item[f] << " -  ";
        for(int c = 0; c < 2; c++){
            cout   << menu[f][c] << "|";
        }
        cout << endl << "========================" << endl;
    }

    cout << "Seleccione el país introduciendo el numero que le corresponda: ";
    cin >> pais; 
    cout << "Ingrese la cantidad de dinero: ";
    cin >> dinero;

    
    return 0;
}