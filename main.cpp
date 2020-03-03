#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream entrada;
    string linha;

    entrada.open("entrada.txt");

    if(!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo.";
        return false;
    }

    while(!entrada.eof()) {
        getline(entrada,linha);
        cout << linha << endl;
    }

    entrada.close();
}