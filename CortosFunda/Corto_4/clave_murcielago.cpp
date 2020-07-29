#include <iostream>
#include <string>
using namespace std;

//Funcion para codificar caracter
char codificarLetra(char letra){
    //Se define una matriz con las equivalencias de las letras de la clave
    char clave[2][10] = {'m','u','r','c','i','e','l','a','g','o',
                         '0','1','2','3','4','5','6','7','8','9'};
    //Se compara el caracter actual con las letras de la primera fila
    for(int i = 0; i< 10; i++){
        //Si este coincide con alguno, se convierte en su equivalente de la segunda fila
        if(tolower(letra) == clave[0][i]) letra = clave[1][i];
    }
    //Se devuelve convertido, o no convertido en caso de no formar parte de la clave
    return letra;
}

int main(){
    //se define una cadena de caracteres y un contador para la longitud
    string texto;
    int l = 0;
    //Se solicita la entrada del texto
    cout << "Ingrese su texto: " << endl;
    getline(cin,texto);
    //Se calcula su longitud
    for(int i = 0; texto[i];i++) l++;
    //Se itera sobre cada caracter, aplicando la clave 
    for(int i = 0; i < l; i++){
        texto[i] = codificarLetra(texto[i]); 
    }
    //Se muestra en pantalla el texto codificado
    cout << "Texto codificado: " << endl;
    cout << texto << endl;
    return 0;
}