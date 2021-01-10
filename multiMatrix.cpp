
/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Multiplicación de Matrices
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> matrices;
vector<vector<int>> mem(210, vector<int>(210, -1));

int multiMatrix (int i, int j){

  //casos bases
  if(i == j) return 0;

  //ya lo calcule
  if(mem[i][j] != -1) return mem[i][j];

  //proceso de calcular el resultado
    mem[i][j] = 1e6;
    for(int k = i; k < j; k++){
        mem[i][j] = min (mem[i][j], multiMatrix(i,k) + multiMatrix(k+1, j) + matrices[i-1] * matrices[k] * matrices[j]);
    }

  return mem[i][j];
}

int main(){

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        matrices.push_back(a);
    }
    
    cout << multiMatrix(1, matrices.size()-1) <<"\n";

return 0;
}
