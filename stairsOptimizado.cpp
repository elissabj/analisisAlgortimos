/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Stairs
3CV3
https://omegaup.com/arena/problem/escalera/#problems
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

lli n, k;
lli mem [1000000];

lli nextInt() {
    lli x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

lli formasDeSubir (lli n ){

  //casos bases
  if(n == 0) return 1;
  if(n < 0) return 0;

  //ya lo calcule
  if(mem[n] != -1) return mem[n];

  lli caminos = 0;
  for(lli i = 1; i <= k; i++){
      caminos += formasDeSubir(n-i);
  }
  
  mem[n] = caminos;
  return mem[n];
}

int main(){

    __
    n = nextInt();
    k = nextInt();
    memset(mem, -1, 1000000);
    cout << formasDeSubir(n) <<"\n";
    
return 0;
}