#include <iostream>
#include <fstream>
#include <string>
#include <new>

using namespace std;

/*
    **  1. Ler arquivo (ok)
    **  2. Pegar num de linhas e colunas (ok)
    **  3. Criar matriz com m linhas e n colunas (ok)
    **  4. Pegar as restrições e aplicar na matriz
    **  5. Simplificar o problema
*/

// Função string to array, converte uma string de numeros em um array desses numeros
int *string_to_array(string str){
    int k= 0, j = 0;
    string c;
    int *arr = new(nothrow) int[str.length()];

    if(arr != nullptr) {
        // for (int i = 0; i < str.length(); i++) {
        //     j = i;
        //     if (str[i] != ' '){ 
        //             while(str[j] != ' ' ){
        //                 c += str[j];
        //                 j++;
        //                 if(str[j] == ' '){
        //                     continue;
        //                 }
        //             }
        //             arr[i] = stoi(c);   
        //     }
        // }
        for (int i = 0; i < str.length(); i++) {
            j = i;
            while (str[j] != ' '){
                --j;
                if(str[j] == ' '){
                    ++j;
                    while (str[j] != ' '){
                        c += str[j];
                        ++j;
                    }
                }
            }
            i = j;
            arr[i] = stoi(c);
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
    int m = 0, n = 0, contador = 0, **matriz = nullptr, *restr = nullptr;

    entrada.open("entrada.txt"); // abre o arquivo

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    cout << "Entrada" << endl;

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
            cout << "Linha: " << linha << endl;
            cout << "linha em um array de int: " << endl;
            for (int i = 0; i < linha.length(); ++i) {
                cout << string_to_array(linha)[i] << " ";
            }
            cout << "tamanho da linha: " << linha.length() <<endl;
            //restr[contador-2] = *string_to_array(linha);
        }
        contador++;
    }
    entrada.close(); //fecha o arquivo

    // Matriz de m linhas por n colunas
    matriz = aloca_matriz(matriz, m, n);

    //cout << "\n" << "matriz " << m << "x" << n << endl;
    //printa_matriz(matriz, m, n);
    //for (int i = 0; i < m-2; i++)
    //cout << linha.length() << " ";

    delete[] matriz;
}
