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

int main(){
    ifstream entrada;
    string token, linha, s, delimiter = " ";
    size_t pos = 0;
    vector<string> v, int_v;

    entrada.open("entrada.txt");

    while(!entrada.is_open()) {
        cerr << "Erro";
        return false;
    }

    while(!entrada.eof()) {
        getline(entrada,linha);
        v = split(linha, ' ');
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
            int_v[i] = stoi(v[i]);
        }

        cout << endl;
    }
    cout << int_v[0];
    return 0;
}
