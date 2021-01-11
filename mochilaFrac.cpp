 /*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Algoritmos Glotones (greedy) - Mochila Fraccionaria
3CV3
*/

#include<bits/stdc++.h>
using namespace std;

//funcion de comparacion peso / valor
bool comparacionPV (pair<int, int>  a, pair<int, int > b){
   
    double p_v1 = (double)a.second / (double)a.first; // Valor / peso 
    double p_v2 = (double)b.second / (double)b.first; // Valor / peso
    
    return p_v1 > p_v2; // Mayor a menor
}

int main (){
    
    //Donde el first es el peso y el second el valor
    vector< pair<int, int> > mochila;
    
    int peso; cin >> peso;
    int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        int peso, valor; cin>> peso >> valor;
        mochila.push_back({peso, valor});
    }
    
    //Comparacion por valor/peso
    sort(mochila.begin(), mochila.end(), comparacionPV);
    
    int pesoActual = 0; // Peso actual de la mochila
    double max_valor = 0.0; // Valor maximo por cada objeto 
    
    //Proceso para calcular el máximo
    for(int i = 0; i < mochila.size(); i++){
        if(pesoActual + mochila[i].first <= peso){ 
            pesoActual += mochila[i].first;
            max_valor += mochila[i].second;
        }else{
            double pesoRestante = peso - pesoActual;
            max_valor += (pesoRestante * mochila[i].second) / mochila[i].first; //regla de 3
            break;
        }
    }
    
    cout << max_valor << endl; 
return 0;
}