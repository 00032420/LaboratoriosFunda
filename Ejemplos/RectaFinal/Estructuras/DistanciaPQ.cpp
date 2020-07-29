#include <iostream>
#include <cmath>

using namespace std;

struct coordenadas{
    float x,y;
};

float distancia(coordenadas punto1, coordenadas punto2){
    return sqrt(pow(punto2.x - punto1.x,2) + pow(punto2.y - punto1.y,2));
};

int main(){
    coordenadas p1, p2;
    float d;

    cout << endl;
    cout << "Distancia entre dos puntos" << endl << endl;
    cout << "Digite las coordenadas del primer punto:" << endl;

    cout << "x1: ";
    cin >> p1.x;
    cout << "y1: ";
    cin >> p1.y;
    
    cout << "Digite las coordenadas del segundo punto:" << endl;

    cout << "x2: ";
    cin >> p2.x;
    cout << "y2: ";
    cin >> p2.y;

    d = distancia(p1,p2);
    cout << "La distancia entre dos puntos es: " << d << endl;
    cout << endl;

    return 0;

}

