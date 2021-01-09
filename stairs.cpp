
/*https://omegaup.com/arena/problem/escalera/#problems
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Stairs
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

long long int n, k;
long long int mem [1000000];

long long int formasDeSubir (long long int n){

  //casos bases
  if(n == 0) return 1;
  if(n < 0) return 0;

  //ya lo calcule
  if(mem[n] != -1) return mem[n];

  //proceso de calcular el camino
  long long int caminos = 0;
  for(long long int i = 1; i <= k; i++){
      caminos += formasDeSubir(n-i);
  }
  //memorizo el resultado
  mem[n] = caminos;

  return mem[n];
}

int main(){

    cin >> n >> k;
    memset(mem, -1, 1000000);
    cout << formasDeSubir(n) <<"\n";

return 0;
}