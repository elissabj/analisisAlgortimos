/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Fibonacci
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

int mem[100];

int fibo(int n){

    mem[0] = 1;
    mem[1] = 1;

    for(int i = 2; i <= n; i++){
        mem[i] = mem[i-1] + mem[i-2];
    }

return mem[n];
}

int main(){

    int n_fibo; 
    cin >> n_fibo;

    cout << fibo(n_fibo) <<"\n";

return 0;
}