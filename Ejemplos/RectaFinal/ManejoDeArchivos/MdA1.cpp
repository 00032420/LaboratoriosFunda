#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream archivo;
    archivo.open("miPrimerArchivo.txt");
    archivo.close();
    return 0;
}