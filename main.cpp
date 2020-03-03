#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    **  1. Ler arquivo (ok)
    **  2. Pegar num de linhas e colunas (ok)
    **  3. Criar matriz com m linhas e n colunas (ok)
    **  4. Pegar as restrições e aplicar na matriz
    **  5. Simplificar o problema
*/

// Printa a matriz desejada
void printa_matriz(int **matriz, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        
        cout << endl;
    }
}

// Aloca a matriz dinamicamente
int **aloca_matriz(int **mat,int m, int n){
    int i;
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
    int m = 0, n = 0, contador = 0, **matriz = nullptr;

    entrada.open("entrada.txt");

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    cout << "Entrada" << endl;

    // Usa um contador para armazenar o numero da linha atual do arquivo, e obter os dados do mesmo
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
    
    cout << "\n" << "matriz " << m << "x" << n << endl;
    printa_matriz(matriz, m, n);

    delete[] matriz;
}
