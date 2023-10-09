#include <iostream>
#include <vector>
using namespace std;

#define Matrix vector<vector<int>>

int millor_premi = 0;

void premi(int m, const Matrix& M, int numero, int lenght, vector<bool>& usat, int valor_premi){

    if (lenght > 0 and numero%m == 0) return;
    if (lenght == int(M.size())){
        if (millor_premi < valor_premi) millor_premi = valor_premi;
        return;
    }
    else{
        for (int i = 0; i < int(M.size()) ; ++i){
            if (not usat[i]){
                usat[i] = true;
                if (lenght == 0) premi(m, M, i+1, lenght + 1, usat, valor_premi);
                else premi(m, M, numero*10 + (i+1), lenght + 1, usat, valor_premi + M[numero%10-1][i]);
                usat[i] = false;
            }
        }
    }
}

void premi(int m, const Matrix& M){
    vector<bool> usat(M.size(), false);
    premi(m, M, 0, 0, usat, 0);
}   

int main(){
    int n, m;
    while (cin >> m >> n){
        Matrix M(n, vector<int>(n, 0));
        for (vector<int>& fila : M) for (int& num: fila) cin >> num;
        premi(m, M);
        cout << millor_premi << endl;
        millor_premi = 0;
    }
    
}