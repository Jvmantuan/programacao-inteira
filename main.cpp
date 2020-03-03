#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void printa_matriz(int **matriz, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        
        cout << endl;
    }
}

int **aloca_matriz(int **mat,int m, int n){
    int i,j;
    mat = (int **) calloc(m, sizeof(int *));
    for(i = 0; i < m; i++){
        mat[i] = (int *) calloc(n, sizeof(int));
        if(mat[i] == nullptr){
            cout << "Erro de alocacao.";
            return nullptr;
        }
    }

return mat;
}

int main(){

    ifstream entrada;
    string linha;
    int m = 0, n = 0, contador = 0, **matriz;

    entrada.open("entrada.txt");

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    while(!entrada.eof()) {
        getline(entrada,linha);
        cout << linha << endl;
        if(contador == 0)
            m = stoi(linha);
        else if(contador == 1)
            n = stoi(linha);
        contador++;
    }
    entrada.close();

    // Matriz de m linhas por n colunas
    matriz = aloca_matriz(matriz, m, n);
    
    printa_matriz(matriz, m, n);
}
