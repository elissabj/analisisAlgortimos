
/*https://codeforces.com/contest/189/problem/A
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Cut Ribbon
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

long long int n, a, b, c;
//long long int mem [5000];
vector<long long int>mem(4100, -1);

long long int maximizarPedazos (long long int n){

  //casos bases
  if(n == 0) return 0;
  if(n < 0) return -1e9;

  //ya lo calcule
  if(mem[n] != -1) return mem[n];

  //proceso de calcular max y memorizo el resultado
  mem[n] = max( maximizarPedazos(n-a), max(maximizarPedazos(n-b), maximizarPedazos(n-c))) + 1;

  return mem[n];
}

int main(){

    cin >> n >> a >> b >> c;
    //memset(mem, -1, 5000);
    cout << maximizarPedazos(n) <<"\n";

return 0;
}