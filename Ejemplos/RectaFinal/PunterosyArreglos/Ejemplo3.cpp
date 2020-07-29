#include <iostream>

using namespace std;

void leerMatriz(int[][25], int, int);
void mostrarMatriz(int [][25], int, int);

int main(void){
    int a[25][25], m,n;

    cout << endl;
    cout << "Ejemplo con una matriz" << endl << endl;

    cout << "Digite las dimensiones de la matriz: " << endl;
    cout << "Cantidad de filas: "; 
    cin >> m;
    cout << "Cantidad de columnas: ";
    cin >> n;

    leerMatriz(a,m,n);
    mostrarMatriz(a,m,n);

    cout << endl;
    return 0;
}

void leerMatriz(int x[][25], int m, int n){
    cout << "digite los siguientes elementos de la matriz: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Elemento de la fila " << i << " y columna " << j << ": ";
            cin >> x[i][j];
        }
    }
}

void mostrarMatriz(int x[][25], int m, int n){
    cout << "La matriz es la siguiente: " << endl;
    for(int i = 0;i<m;i++){
        for(int j = 0; j < n; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
}