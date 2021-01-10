 /*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Algoritmos Glotones (greedy) - Selección de actividades
3CV3
Casos de prueba
 s = 6
 {5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}
 res = 4
 s = 11
 {1, 4}, {12, 14}, {3, 5}, {2, 13}, {0, 6}, {8, 12}, {5, 7}, {8, 11}, {3, 8}, {6, 10}, {5, 9}
 res = 4
*/
 #include<bits/stdc++.h>
 using namespace std;
 
 //funcion que me ayuda a ordenarlos por el segundo valor
 bool ordenarPorSegundo(pair<int, int> & a, pair<int, int> & b){
     return a.second < b.second;
 }
 
 int main(){
     
     //leo la cantidad de activades y leo cada par
     int conjunto; cin >> conjunto; 
     
     vector<pair<int, int>> valor_act(conjunto);
     for(auto & [x,y]: valor_act){
         cin >> x >> y;
     }
     
     //ordeno por el fin de las actividades
     sort(valor_act.begin(), valor_act.end(), ordenarPorSegundo);
     
     //proceso mi respuesta
     vector< pair<int, int> > res = {valor_act[0]};
     for(int i = 1; i < conjunto; i++){
         if( valor_act[i].first >= res[res.size()-1].second){
             res.push_back(valor_act[i]);
         }
     }
     
     //imprimo respuesta
     cout << res.size()<<"\n"; 
     for(auto x: res){
         cout << x.first << " " << x.second <<"\n"; 
     }
 return 0;
 }
 
