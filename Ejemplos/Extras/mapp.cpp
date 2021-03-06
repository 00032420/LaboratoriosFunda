#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>

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
    return abs(producto)/sobre;
}

string vectorm(float producto, float bx, float by, float bz, float magnitudb){
    float prim = abs(producto)/(pow(magnitudb,2));
    return to_string(prim*bx) + "i, " + to_string(prim*by) + "j, " + to_string(prim*bz) + "k ";
}

string entreAB(float ax, float ay, float az, float bx, float by, float bz){
    return to_string(bx-ax) + "i, " + to_string(by-ay) + "j, " + to_string(bz-az) + "z";
}

string entreBA(float ax, float ay, float az, float bx, float by, float bz){
    return to_string(ax-bx) + "i, " + to_string(ay-by) + "j, " + to_string(az-bz) + "z";
}

float redondear(float var){
    float value = (int) (var*100 + .5);
    return (float)value / 100;
}

int main(){
    string i1, j1, k1, i2, j2, k2, vector_proy1, vector_proy2, ab,ba;
    
    float ax, ay, az, bx, by, bz, m1, m2, pe, rad, deg, proy1, proy2;
    long double pi = 3.14159265359;
    
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
    
    m1 = (magnitud(ax,ay,az)); 
    m2 = (magnitud(bx,by,bz)); 
    pe = (producto(ax,ay,az,bx,by,bz));
    rad = (angulo(pe, m1, m2));
    deg = (rad*(180/pi));
    proy1 = (proyeccion_escalar(pe,m2));
    proy2 = (proyeccion_escalar(pe,m1));
    vector_proy1 = vectorm((pe),(bx),(by),(bz),(m2));
    vector_proy2 = vectorm((pe),(ax),(ay),(az),(m1));
    ab = entreAB(ax,ay,az,bx,by,bz);
    ba = entreBA(ax,ay,az,bx,by,bz);
    

    cout << "La magnitud del primer vector es " <<  std::fixed << std::setprecision(2) << (m1) << endl;
    cout << "La magnitud del segundo vector es " << std::fixed << std::setprecision(2) << (m2) << endl;
    cout << "El producto escalar es " << std::fixed << std::setprecision(2) << (pe) << endl;
    cout << "El angulo entre ellos es " << std::fixed << std::setprecision(2) << (rad) << " radianes/ " << std::fixed << std::setprecision(2) << deg << " grados" << endl;
    cout << "La proyeccion del primero sobre el segundo es " << std::fixed << std::setprecision(2) << (proy1) << endl;
    cout << "El vector proyeccion del primero sobre el segundo es " << vector_proy1 << endl;
    cout << "La proyeccion del segundo sobre el primero es " << std::fixed << std::setprecision(2) << (proy2) << endl;
    cout << "El vector proyeccion del segundo sobre el primero es " << vector_proy2 << endl;
    cout << "El vector entre el primero al segundo es " << ab << endl;
    cout << "El vector entre el segundo al primero es " << ba << endl;

    system("pause");
    return 0;
}