/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Fast Fourier Transform
3CV3
*/
#include <bits/stdc++.h>
using namespace std;

void fft(vector<complex<double>> & valores, int inv){
	
    int tam = valores.size();
	if(tam == 1) return;

	vector<complex<double>> par(tam/2), impar(tam/2);

	for(int i = 0; i < tam; ++i){
		if(i&1) impar[i/2] = valores[i];
		else par[i/2] = valores[i];
	}

	fft(par, inv), fft(impar, inv);
	complex<double> w = polar(1.0, 2*(acos(-1))*inv/tam), wk = 1, u, v;

	for(int i = 0; i < tam/2; ++i, wk *= w){
		u = par[i], v = wk * impar[i];
		valores[i] = u + v;
		valores[i+tam/2] = u - v;
	}

	if(inv == -1)
		for(int i = 0; i < tam; ++i)
			valores[i] /= 2;
}

int main (){
    vector<complex<double>> numeros;
    
    numeros.push_back(1);
    numeros.push_back(2);
    numeros.push_back(3);
    numeros.push_back(4);
    numeros.push_back(5);
   
    fft(numeros, 1);
    
    cout<<"FFT\n";
    
    for(auto valor: numeros){
        cout << valor << endl;
    }    
return 0;
}
