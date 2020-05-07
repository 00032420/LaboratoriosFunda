#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

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

float magnitud(float x, float y, float z){
    return  sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

float producto(float ax, float ay, float az, float bx, float by, float bz){
    return (ax*bx)+(ay*by)+(az*bz);
}

float angulo(float producto, float magnitud1, float magnitud2){
    return acos((producto)/((magnitud1)*(magnitud2)));
}

float proyeccion_escalar(float producto, float sobre){
    return producto/sobre;
}

int main(){
    string i1, j1, k1, i2, j2, k2;
    
    float ax, ay, az, bx, by, bz, m1, m2, pe, rad, proy1, proy2;
    
    cout << "X1: "; 
    ax = convertir(i1);
   
    cout << "Y1: ";
    ay = convertir(j1);
   
    cout << "Z1: ";
    az = convertir(k1);

    cout << "X2: "; 
    bx = convertir(i2);
   
    cout << "Y2: ";
    by = convertir(j2);
   
    cout << "Z2: ";
    bz = convertir(k2);
    
    //Se promedian las cantidades y se almacenan en la variable
    m1 = magnitud(ax,ay,az); 
    m2 = magnitud(bx,by,bz); 
    pe = producto(ax,ay,az,bx,by,bz);
    rad = angulo(pe, m1, m2);
    proy1 = proyeccion_escalar(pe,m2);
    proy2 = proyeccion_escalar(pe,m1);

    //Se muetra el resultado. 
    cout << "La magnitud del primer vector es " << m1 << endl;
    cout << "La magnitud del segundo vector es " << m2 << endl;
    cout << "El producto escalar es " << pe << endl;
    cout << "El angulo entre ellos es " << rad << " radianes" << endl;
    cout << "La proyección de A sobre B es " << proy1 << endl;
    cout << "La proyección de B sobre A es " << proy2 << endl;


    system("pause");
    return 0;
}