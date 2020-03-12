#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Retorna a quantidade de elementos maiores ou iguais que 1
int qtd_elementos(int **matriz, int linha, int n_colunas) {
    int soma = 0;

    for (int j = 0; j < n_colunas; j++) {
        if (matriz[linha][j] >= 1)
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
    ofstream saida; 
    string linha, c;
    int j = 0, m = 0, n = 0, contador = 0,obj, i;


    entrada.open("entrada6.txt"); // abre o arquivo

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    getline(entrada, linha);
    m = stoi(linha); //ObtÃƒÆ’Ã‚Â©m o numero de objetos

    getline(entrada, linha);
    n = stoi(linha); //ObtÃƒÆ’Ã‚Â©m o numero de subconjuntos

    int **matriz = aloca_matriz(matriz, m, n);

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
	
	int vector_aux[n];
	int soma_aux = 0, tam1, tam2;
	string cons;
	saida.open("saidajv.txt", ios::out);

    saida << "Minimize" << endl;
    saida << " obj: ";
    
    string obj_s; i = 1;
    while(i <= n){
    	obj_s += "x" + to_string(i) + " + ";
        i++;
    }
    obj_s.erase(obj_s.end() - 3, obj_s.end());
	
    saida << obj_s << endl;
    
    int v_aux[m];
    
    for(int i = 0; i < m; i++)
    	v_aux[i] = 0;
    	    
    for(int i = 0; i < m; i++){
    	for(j = 0; j < n; j++){
			v_aux[i] += matriz[i][j];
		}
	}
    
    
    saida << "Subject To" << endl;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < m; k++) {
			if(k > i){
				soma_aux = 0;
				for (int j = 0; j < n; j++){
					if(matriz[i][j] + matriz[k][j] == 2){
						vector_aux[j] = 1;
						soma_aux++;
					}else
						vector_aux[j] = 0;
	
				if(qtd_elementos(matriz,i,n) == soma_aux) 
						v_aux[k] = -1;
				else if(qtd_elementos(matriz,k,n) == soma_aux) 
						v_aux[i] = -1;
				}
						
			}
		}
	}
	
	for(int i = 0; i < m; i++){
			cons.clear();
		if(v_aux[i] != 1 && v_aux[i] != -1){
			for(int j = 0; j < n; j++){
				if(matriz[i][j] == 1)
					cons += "x" + to_string(j+1) + " + ";	
			}
			cons.erase(cons.end() - 3, cons.end());
			saida << " c" << i + 1 << ": " << cons << " >= 1\n";
		}
		else 
			continue;
	}
	
	int restr[n];
	
	for(int i = 0;i < n; i++)
		restr[i] = 0;
	
    saida << "Bounds" << endl;
    for(int i = 0; i < m; i++){
    	if(qtd_elementos(matriz,i,n) == 1){
    		for(int j = 0; j < n; j++){
    			if(matriz[i][j] == 1){
    				restr[j] = 1;
				}
			} 
		}else
			restr[j] = 0;
    }
    
    for(int j = 0; j < n; j++)
    	cout << restr[j] << " ";
    cout << endl;
    
    for(int j = 0; j < n; j++)
	    if(restr[j] == 1)
			saida << " 1 <= x" << to_string(j+1) << " <= 1" << "\n";				 	
		else
			saida << " 0 <= x" << to_string(j+1) << " <= 1" << "\n";
    saida << "General" << endl;
    
    i = 1;
    while(i <= n){
        saida << " x" << i;
        i++;
    }
	
    saida << "\nEnd" << endl;
    
    saida.close();
	
	
	printar_matriz(matriz,m,n);
	for(int i = 0; i < n; i++)
	cout << restr[i] << " ";
	
    free(matriz);
}
