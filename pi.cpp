#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Retorna a quantidade de elementos maiores ou iguais que 1
int qtd_elementos(int **matriz, int n_linhas, int n_colunas) {
    int soma = 0;

    for (int j = 0; j < n_colunas; j++) {
        if (matriz[n_linhas][j] >= 1)
            soma++;
    }
    return soma;
}

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

void printar_matriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

int main() {

    ifstream entrada; // var responsavel pela abertura de um arquivo
    ofstream saida; //
    string linha, c;
    int j = 0, m = 0, n = 0, contador = 0;


    entrada.open("entrada.txt"); // abre o arquivo

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    getline(entrada, linha);
    m = stoi(linha); //Obt�m o numero de objetos

    getline(entrada, linha);
    n = stoi(linha); //Obt�m o numero de subconjuntos

    int **matriz = aloca_matriz(matriz, m, n);
    int **matriz_aux = aloca_matriz(matriz_aux, m, n);

    while (getline(entrada, linha)) {
        c.clear();
        for (int i = 0; i < linha.length(); i++) {
            if (linha[i] != ' ') {
                c += linha[i];
            } else {
                matriz[stoi(c) - 1][j] = 1;
                c.clear();
            }
        }
        matriz[stoi(c) - 1][j] = 1;
        c.clear();
        j++;
    }

    entrada.close();

    int min = 1000000, n_elementos = 0, lin = 0, col = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i >= 1){
				matriz_aux[i][j] = matriz[i][j] + matriz[i-1][j];
			}
			//for(int k = 0; k < )
		}
	}
	
    printar_matriz(matriz_aux, m, n);

    free(matriz);
}
