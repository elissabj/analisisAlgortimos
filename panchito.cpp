//https://omegaup.com/arena/problem/pachito-tareas/#problems/pachito-tareas
#include<bits/stdc++.h>
using namespace std;
 
long long tam = 0; 
long long cont = 0;
long long numero_tareas; 
long long maximo_tareas = 0;


void merge(vector<long long> &tempo, long long &izq, long long &mitad, long long &der) 
{ 
    long long n1 = mitad - izq + 1; 
    long long  n2 = der - mitad; 


    long long  IZQ[n1], DER[n2];     
    for(long long i = 0; i < n1; i++) 
        IZQ[i] = tempo[izq + i]; 
    for(long long j = 0; j < n2; j++) 
        DER[j] = tempo[mitad + 1 + j]; 


    long long  i = 0;  
    long long  j = 0;  
    long long  k = izq; 
      
    while (i < n1 && j < n2){ 
        if (IZQ[i] <= DER[j]){ 
            tempo[k] = IZQ[i]; 
            i++; 
        }else{ 
            tempo[k] = DER[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        tempo[k] = IZQ[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        tempo[k] = DER[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(vector<long long> &tempo, long long izq, long long  der) 
{ 
    if (izq < der){ 
        long long  mitad = izq + (der - izq) / 2; 
  
        mergeSort(tempo, izq, mitad); 
        mergeSort(tempo, mitad + 1, der); 
  
        merge(tempo, izq, mitad, der); 
    } 
} 


int main(){ 
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> tam >> numero_tareas; 
    vector<long long> tiempo(tam); 
    for(auto & x: tiempo){
        cin  >> x;
    }    
  
    mergeSort(tiempo, 0, tiempo.size()-1);

    for(long long i = 0; i < tam; i++){
        numero_tareas -= tiempo[i];
        if(numero_tareas <= 0){
            break;
        }else{
            cont++;
        }
    }

  cout << cont <<"\n";
return 0; 
} 

