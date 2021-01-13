 /*
INSTITUTO POLITÉCNICO NACIONAL 
Escuela Superior de Computo
Análisis de Algortimos
Ramos Gómez Elisa
Algoritmos Glotones (greedy) - Códigos Huffman
3CV3
*/
#include <bits/stdc++.h> 
using namespace std; 

// Nodo del arbol de Huffman
struct MinHeapNode { 
    
    //Caracter del nodo 
    char data; 
    //Frecuencia del caracter 
    long long freq;
    
    //Hijo izquierdo y derecho 
    MinHeapNode *left, *right; 
    
    //Constructor del nodo
    MinHeapNode(char data, long long freq){ 
        left = right = nullptr; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
  
//Funcion de comparacion de dos nodos de nuestro heap de minimos
struct compare { 
  
    bool operator()(MinHeapNode* l, MinHeapNode* r) { 
        return (l->freq > r->freq); 
    } 
}; 
  
//Funcion para imprimir los nodos y asignarle el codigo
void printCodes(struct MinHeapNode* root, string str) { 
  
    if (!root) 
        return; 
  
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
  
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1");
} 

//Funcion para hacer el arbol de Huffman
void HuffmanCodes(vector < pair<char, int> > char_freq) { 
    
    //Hijo derecho, izquierdo y raiz
    MinHeapNode *left, *right, *top; 
  
    //Esto es el heap de minimos con cada nodo del arbol de Huffman
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
  
    //Y construimos al principio metiendo en cada nodo nuestro nodo ya hecho
    for (int i = 0; i < char_freq.size(); ++i) 
        minHeap.push(new MinHeapNode(char_freq[i].first, char_freq[i].second)); 
    
    // Iterate while size of heap doesn't become 1 
    
    //Iteramos hasta tener un solo nodo en el arbol de minimos que es el que va a tener
    //todo el arbol de Huffman construido
    while (minHeap.size() != 1) { 
        
        //Tomamos los dos nodos con la frecuencia menor dentro del heap 
        
        //Y los asignamos a uno izquierdo
        left = minHeap.top(); 
        minHeap.pop(); 
        
        //Y a uno derecho
        right = minHeap.top(); 
        minHeap.pop(); 
        
        /*
         * Creamos un nuevo nodo con una frecuencia que es la suma de las dos frecuencias
         * tomadas de los dos nodos menores del heap de minimos y les asignamos esos dos nodos
         * a su hijo izquierdo y a su hijo derecho, y a ese nodo le ponemos el caracter 
         * centinela '$' para identificar que es el nuevo nodo y este nodo lo volvemos a meter
         * en nuestro heap de minimos
         */
        
        top = new MinHeapNode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        minHeap.push(top); 
    } 
  
    //Imprimimos los codigos con la funcion que atraviesa el arbol de Huffman
    printCodes(minHeap.top(), ""); 
}

int main(){ 
    
    /*  	Para codigos de Huffman se sigue lo siguiente:
     * Entrada -> Construccion del arbol -> Atravesar el arbol (Preorder) -> Asignar el codigo en el recorrido.
    */
    
    //Almacenamos el caracter y su frecuencia
    vector < pair<char, int> > char_freq;
    
    //Caso de prueba
    char_freq = {{'a',5}, {'b',9}, {'c',12}, {'d',13}, {'e',16}, {'f',45}, {'g',1}};
    
    for(auto x: char_freq){
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    
    //Mandamos a llamar la funcion para asignar el codigo de Huffman
    HuffmanCodes(char_freq);
  
    return 0; 
}