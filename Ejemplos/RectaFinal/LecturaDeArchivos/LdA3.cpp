#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string dato;
    int i,k;

    cout << endl;
    cout << "Leer palabra por palabra desde un archivo" << endl << endl;

    ifstream archivo;
    archivo.open("archivo08.txt");

    i = 0;
    while(!archivo.eof()){
        archivo >> dato;
        cout << dato << endl;
    }

    archivo.close();

    cout << endl;
    return 0;
}