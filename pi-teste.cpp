#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <vector>
#include <sstream>

using namespace std;

/*
    **  1. Ler arquivo (ok)
    **  2. Pegar num de linhas e colunas (ok)
    **  3. Criar matriz com m linhas e n colunas (ok)
    **  4. Pegar as restri��es e aplicar na matriz
    **  5. Simplificar o problema
*/


// Aloca a matriz dinamicamente
int **aloca_matriz(int **mat, int m, int n) {
    int i;
    mat = (int **) calloc(m, sizeof(int *));
    for (i = 0; i < m; i++) {
        mat[i] = (int *) calloc(n, sizeof(int));
        if (mat[i] == nullptr) {
            cout << "Erro de alocacao.";
            return nullptr;
        }
    }

    return mat;
}

int main() {

    ifstream entrada; // var responsavel pela abertura de um arquivo
    string linha, c;
    int j, m = 0, n = 0, contador = 0;


    entrada.open("entrada2.txt"); // abre o arquivo

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    getline(entrada, linha);
    m = stoi(linha);

    getline(entrada, linha);
    n = stoi(linha);

    int **matriz = aloca_matriz(matriz,m,n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    j = 0;
    //for(j = 0; j < n; j++) {
    while (getline(entrada, linha)) {
        c.clear();
        for (int i = 0; i < linha.length(); i++) {
            if (linha[i] != ' ')
                c += linha[i];
            else {
                //cout << c << endl;
                matriz[stoi(c) - 1][j] = 1;
                c.clear();
            }
        }
        matriz[stoi(c) - 1][j] = 1;
		c.clear();
		j++;
    }
    entrada.close();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    //free(matriz);
}
