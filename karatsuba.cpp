/*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Cómputo
Análisis de Algortimos
Ramos Gómez Elisa
Algoritmo Karatsuba
3CV3
*/
#include<bits/stdc++.h>
using namespace std;

//funcion que me dice cual es menor
bool esMenor(string x, string y){
    
    int n1 = x.length(), n2 = y.length();

    if (n1 < n2) return true;
    if (n2 < n1) return false;


    for (int i = 0; i < n1; i++)
        if (x[i] < y[i])
            return true;
        else if (x[i] > y[i])
            return false;
 
    return false;
}

//funcion que resta dos numeros como cadenas
string restaNumCadenas (string x, string y){
    if (esMenor(x, y)) swap(x, y);
 
    int acarreo = 0;
    string respuesta = "";
    int n1 = x.length(), n2 = y.length();

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
 

    for (int i = 0; i < n2; i++) {
        int sub = ((x[i] - '0') - (y[i] - '0') - acarreo);
        if (sub < 0) {
            sub = sub + 10;
            acarreo = 1; //si la resta es menor a 10, sumamos y llevamos el acarreo
        }else{
            acarreo = 0;
        }     
        respuesta.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((x[i] - '0') - acarreo);
        if (sub < 0) {
            sub = sub + 10;
            acarreo = 1;
        }
        else{
            acarreo = 0;
        }
        respuesta.push_back(sub + '0');
    }
    reverse(respuesta.begin(), respuesta.end());
    return respuesta;
}


//funcion que suma dos numeros como cadenas
string sumaNumCadenas (string x, string y){
    string aux;
    int acarreo = 0;
    for(int i = x.size()-1, j = y.size()-1; i >= 0 ; ++j ,i++){
        int suma = x[i]-'0'+ y[j]-'0'+ acarreo;
        aux.push_back(suma%10+'0');
        acarreo = suma / 10;
    }
    if (acarreo > 0) aux.push_back(acarreo + '0');
    reverse(aux.begin(), aux.end());
    return aux;
}

//funcion agregar ceros
string agregoCeros (string w, int cantidad_ceros, bool agrego_izq = true){
    string aux = w;
    for(int i = 0; i < cantidad_ceros; i++){
        if(!agrego_izq){
            aux += '0';
        }else{
            aux = '0' + aux;
        }
    }
    return aux;
}

string karat(string a, string b){
    //caso base cuando ya llegue a nueve digitos o menos que me cuesta constante
    if(a.size() <= 9 && b.size() <= 9){
        long long ans = stol(a) * stol(b);
        return to_string(ans);
    }

    //checo cual es menor y agrego ceros
    if(a.size() > b.size()){
        b = agregoCeros (b,(a.size() - b.size()));
    }else{
        a = agregoCeros (a,(b.size() - a.size()));
    }

    long long tam = a.size();
    long long mitad = tam/2;
    if(mitad % 2 != 0) mitad +=1;

    int b_con_ceros = tam - mitad;
    int a_con_ceros = b_con_ceros * 2;

    string x = a.substr(0, mitad);
    string y = a.substr(mitad, tam);
    string w = b.substr(0, mitad);
    string z = b.substr(mitad, tam);

    string xw = karat(x, w);
    string yz = karat(y, z);

    string k = karat(sumaNumCadenas(x,y), sumaNumCadenas(w,z));

    string a_final = agregoCeros(xw, a_con_ceros, false);
    string b_final = agregoCeros(restaNumCadenas(restaNumCadenas(k,xw),yz), b_con_ceros, false);

    return sumaNumCadenas(sumaNumCadenas(a_final, b_final), yz);
}

int main(){

    string a,b;
    cin >> a >> b;

    string res = karat(a,b);
    cout << res <<"\n";
return 0;
}