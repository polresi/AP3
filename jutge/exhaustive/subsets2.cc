#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subsets(int m, int n, int idx, vector<bool>& resultat, const vector<string>& s, int j){ 
    
    if (j > m) return;
    if (j + (n - idx) < m) return;

    if (idx == n){
        bool primer = true;
        cout << "{";
        for (int k = 0; k < n; ++k){
            if (primer and resultat[k]){
                cout << s[k];
                primer = false;
            }
            else if (resultat[k]){
                cout << "," << s[k];
            }
        }
        cout << "}" << endl;
    }
    else{
        resultat[idx] = false;
        subsets(m, n, idx + 1, resultat, s, j);
        resultat[idx] = true;
        subsets(m, n, idx + 1, resultat, s, j+1);
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<string> s(n);
    vector<bool> resultat(n, false);
    for(string& element: s) cin >> element;
    subsets(m, n, 0, resultat, s, 0);
}