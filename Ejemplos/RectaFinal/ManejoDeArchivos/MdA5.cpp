#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream archivo("archivo05.txt", ios::app);
    archivo << "Una frase\n";
    archivo.close();
    return 0;
}