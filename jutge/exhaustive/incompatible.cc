#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

void permutacions(int n,unordered_map<char,unordered_set<char>>& relacions, const vector<char>& especies, 
                vector<bool>& usat, int j, vector<char>& resultat){
    if (j == n){
        for (char element : resultat) cout << element;
        cout << endl;
    }
    else if (j == 0){
        for (int k = 0; k<n ;++k){
            resultat[j] = especies[k];
            usat[k] = true;
            permutacions(n, relacions, especies, usat, j+1, resultat);
            usat[k] = false;
        }
    }
    else{
        for (int k = 0; k<n ;++k){
            char especie_anterior = resultat[j-1];
            if (not usat[k] and not relacions[especie_anterior].count(especies[k])){
                resultat[j] = especies[k];
                usat[k] = true;
                permutacions(n, relacions, especies, usat, j+1, resultat);
                usat[k] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector <char> especies(n);
    for (char& especie: especies) cin >> especie;
    int m;
    cin >> m;
    unordered_map<char, unordered_set<char>> relacions;
    for (int i = 0; i<m ;++i){
        string inco;
        cin >>inco;
        relacions[inco[0]].insert(inco[1]);
        relacions[inco[1]].insert(inco[0]);
    }
    vector<char> resultat(n);
    vector<bool> usat(n, false);
    permutacions(n, relacions, especies, usat, 0, resultat);

}