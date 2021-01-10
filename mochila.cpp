
/*https://www.spoj.com/problems/KNAPSACK/
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming Mochila
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> mochila;
vector<vector<int>> mem(2100, vector<int>(2100, -1));

int llenarMochila (int peso_actual, int i){

  //casos bases
  if(i == -1 || peso_actual <= 0) return 0;

  //ya lo calcule
  if(mem[peso_actual][i] != -1) return mem[peso_actual][i];

  //proceso de calcular el resultado
  if(mochila[i].first <= peso_actual){
      mem[peso_actual][i] = max( llenarMochila(peso_actual-mochila[i].first, i-1) + mochila[i].second , llenarMochila(peso_actual, i-1));
      return mem[peso_actual][i];
  } 

  mem[peso_actual][i] = llenarMochila (peso_actual, i-1);
  return mem[peso_actual][i];
}

int main(){

    int s, n;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        int p, val; cin >> p >> val;
        mochila.push_back({p,val});
    }
    cout << llenarMochila (s,mochila.size()-1) <<"\n";

return 0;
}
