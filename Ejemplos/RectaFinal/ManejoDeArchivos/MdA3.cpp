#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string nombre = "ar1";
    ofstream archivo(nombre + ".txt");
    archivo << "Me llamo Anita" << endl << endl;
    archivo.close();
    return 0;
}