
/*https://leetcode.com/problems/longest-common-subsequence/
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Dynamic Programming LCS longest common subsecuence
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

string s1, s2;
vector<vector<int>> mem(1200, vector<int>(1200, -1));

int lcs (int i, int j){

  //casos bases
  if(i == 0) return 0;
  if(j == 0) return 0;

  //ya lo calcule
  if(mem[i][j] != -1) return mem[i][j];

  //proceso de calcular el resultado
  mem[i][j] = lcs(i-1, j-1) + 1;
  if(s1[i-1] == s2[j-1]) return mem[i][j];

  mem[i][j] = max (lcs(i, j-1), lcs(i-1, j));

  return mem[i][j];
}

int main(){

    cin >> s1 >> s2;
    cout << lcs (s1.size(), s2.size()) <<"\n";

return 0;
}

/*
//proceso de calcular el resultado en leetcode
  //if(s1[i-1] == s2[j-1]) return lcs(i-1, j-1) + 1;
    class Solution {

private:
    vector<vector<int>> mem;
    string s1, s2;
public:
    
    //de solucion iniciame el vector que tengo declarado en el private
    Solution(): mem(1100, vector<int>(1100, -1)){} 
    
    int lcs (int i, int j){
        //casos bases
        if(i == 0 || j == 0) return 0;

        //ya lo calcule
        if(mem[i][j] != -1) return mem[i][j];

        //proceso de calcular el resultado
        mem[i][j] = lcs(i-1, j-1) + 1;
        if(s1[i-1] == s2[j-1]) return mem[i][j];

        mem[i][j] = max (lcs(i, j-1), lcs(i-1, j));

        return mem[i][j];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1; s2 = text2;
        return lcs(text1.size(), text2.size());
    }
};
*/
