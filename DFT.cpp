/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Discrete Fourier Transform
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<double> numeros(10); // numeros a recibir
    vector<complex<double>> respuesta(10); // respuesta

//leo los numeros a + ib
    for(int i = 0; i < 10; i++){
        cin >> numeros[i];
    }
 
    double x = 0;
    double y = 0;
    //aplico la formula
    for(int i = 0; i < numeros.size(); i++){
        for(int j = 0; j < numeros.size()-1; j++){
            x += numeros[j]*cos((2*i*j*3.14159)/10.0);
            y += numeros[j]*-sin((2*i*j*3.14159)/10.0);
        }
        complex<double> aux (x,y);
        cout << aux.real() <<" + "<<aux.imag()<<"i\n";
        respuesta.push_back(aux);
        x = 0, y = 0;
    }

    /*for(auto z: respuesta){
        cout << z <<endl;
        //cout << z.real() <<" + "<<z.imag()<<"i\n";
    }*/
    
return 0;
}