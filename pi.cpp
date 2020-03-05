#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delimiter){
    vector<string> result;
    stringstream ss(s);
    string item;

    while(getline(ss, item, delimiter)) {
        result.push_back((item));
    }
    return result;
}

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

void printa_matriz(int **matriz, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";

        cout << endl;
    }
}

int main(){
    ifstream entrada;
    string token, linha, s, delimiter = " ";
    size_t pos = 0;
    vector<string> v;
    vector<string> int_v;
    int cont = 0, m, n, **matriz = nullptr;

    entrada.open("entrada.txt");
	
	
	
    while(!entrada.is_open()) {
        cerr << "Erro";
        return false;
    }
	
    while(!entrada.eof()) {
        getline(entrada,linha);
        if(cont == 0)
        	m = stoi(linha);
        else if(cont == 1)
        	n = stoi(linha);
        cont++;
	}
	entrada.close();
	
	entrada.open("entrada.txt");
	
	matriz = aloca_matriz(matriz, m,n);
	
	while(!entrada.eof()) {
		getline(entrada,linha);
		v = split(linha, ' ');
        for(int i = 0; i < v.size(); i++){
        	
			//	cout << v[i] << " ";
            //int_v[i] = v[i];
       	}
	}
	entrada.close();
	printa_matriz(matriz,m,n);
    //cout << int_v[0];
    return 0;
}
