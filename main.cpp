#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <array>

using namespace std;

/*
    **  1. Ler arquivo (ok)
    **  2. Pegar num de linhas e colunas (ok)
    **  3. Criar matriz com m linhas e n colunas (ok)
    **  4. Pegar as restrições e aplicar na matriz
    **  5. Simplificar o problema
*/

// Função que conta os espaços de uma string. Usamos ela para obtermos apenas o tamanho da string sem os espaços.
int conta_espacos(string str){
    int num_espacos = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ')
            num_espacos++;
        if(str[i] == '\n'){
            num_espacos = 0;
            break;
        }
    }
    return num_espacos;
}

int *string_to_array(string str){
    int cont = 0, k= 0, j = 0;
    string c;

    int *arr = new(nothrow) int[str.length() - conta_espacos(str)];

    if(arr != nullptr) {
        for (int i = 0; i < str.length(); i++) {
            j = i;
            if(str[i] != ' '){
                while(str[j] != ' '){
                    if(str[j] != '\n'){
                        c += str[j];
                        ++j;
                    }
                    else break;
                }
                if(str[j] != '\n'){
                    arr[k++] = stoi(c);
                    c.clear();
                }
                else break;
            }
            else{++j;}
            i = j - 1;
        }
        return arr;
    }
}

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

    ifstream entrada; // var responsavel pela abertura de um arquivo
    string linha;
    int m = 0, n = 0, contador = 0, **matriz = nullptr, *restr = nullptr, *restr_matriz = nullptr;

    entrada.open("entrada.txt"); // abre o arquivo

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    //cout << "Entrada" << endl;

    // Usa um contador para armazenar o numero da linha atual do arquivo, e obter os dados do mesmo
    while(!entrada.eof()) {
        getline(entrada,linha);
        //cout << linha << endl;
        if(contador == 0)
            m = stoi(linha);
        else if(contador == 1){
            n = stoi(linha);
            restr = new(nothrow) int[n-2];
        }
        else{
            // Aqui printa a linha atual e embaixo printa os elementos dessa linha convertidos em int
            // pelo método string_to_array()
            cout << linha << endl;
            cout << "linha em um array de int: ";
            restr_matriz = new(nothrow) int[10];
            restr = string_to_array(linha);
            for (int i = 0; i < (conta_espacos(linha)); ++i)
                cout << restr[i] << " ";
            cout << endl;
        }
        contador++;
    }
    entrada.close(); //fecha o arquivo

    // Matriz de m linhas por n colunas
    matriz = aloca_matriz(matriz, m, n);

    //cout << "\n" << "matriz " << m << "x" << n << endl;

    // i = posição do 1 - 1, j = linha -1
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 4; j++){
            if(i == restr[i] - 1 && j == 0){
                matriz[i][j] = restr[j];
            }
        }

    //printa_matriz(matriz, m, n);

    delete[] matriz;
}
