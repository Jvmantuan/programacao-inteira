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
    **  4. Pegar as restrições e aplicar na matriz
    **  5. Simplificar o problema
*/

vector<string> split(const string &s, char delimiter){
    vector<string> result;
    stringstream ss(s);
    string item;

    while(getline(ss, item, delimiter)) {
        result.push_back((item));
    }
    return result;
}

// Função que conta os espaços de uma string. Usamos ela para obter apenas o tamanho da string sem os espaços.
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

// Função que transforma uma string de números em um vetor de inteiros com esses números
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
    }
        return arr;
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

// Lê o entrada.txt e conta a quantidade de linhas
int conta_linhas(){
    ifstream arq;
    int contador = 0; string line;

    arq.open("entrada.txt");

    if(!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    while (!arq.eof()) {
        getline(arq,line);
        contador++;
    }
    arq.close();

    return contador;
}

int main(){

    ifstream entrada, entrada2; // var responsavel pela abertura de um arquivo
    string linha, c;
    int j = 0, m = 0, n = 0, contador = 0, *restr = nullptr;

	
    entrada.open("entrada.txt"); // abre o arquivo

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    //Usa um contador para armazenar o numero da linha atual do arquivo, e obter os dados do mesmo
    while(!entrada.eof()) {
        getline(entrada,linha);
    //     //cout << linha << endl;
        if(contador == 0)
            m = stoi(linha);
        else if(contador == 1){
            n = stoi(linha);
        }
        contador++;
    }
    entrada.close(); //fecha o arquivo
	
	int matriz[m][n];
    restr = new(nothrow) int[n-2];
	
	for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
    		matriz[i][j] = 0;
		}
	}
	
    // Matriz de m linhas por n colunas
    //matriz = aloca_matriz(matriz, m, n);

    // Reabre o arquivo e pra cada linha, aplica na matriz do problema

    entrada.open("entrada.txt");

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    // contador volta para 0 para fazer a função de contar a linha atual
   	contador = 0;
    c.clear();
		j = 0;
    for(j = 0; j < n; j++) {
        getline(entrada,linha);
        if(contador >= 2){
        	for(int i = 0; i < linha.length(); i++){
				if(linha[i] != ' ')
        			c += linha[i];
        		else {
        			matriz[stoi(c) -1][j] = 1;
        			c.clear();
				}
				j++;
			}
            //restr = string_to_array(linha);
			//restricao = split(linha, ' ');
			
			
			
            //cout << "linha em um array de int: " << endl;
            //for (int i = 0; i < conta_espacos(linha); ++i)
            //    cout << restricao[i] << " ";
            //cout << endl;

            // i = posição do 1 - 1, j = linha -1
		}
        contador++;
    }

    entrada.close();
    
    

    for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
    		cout<< matriz[i][j] << ' ';
		}
	cout << endl;
	}
	
    //free(matriz);
}
