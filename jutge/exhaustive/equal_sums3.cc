#include <iostream>
#include <vector>
using namespace std;

void combinacions(int n, int j, 
const vector<int>& valors, vector<bool>& out, int sum, int s, const vector<int>& suma_total){
    
    if (sum > s) return;

    if (j < n and sum + suma_total[n] - suma_total[j] < s) return;

    if (j == n){
        if (sum != s) return;
        cout << "{";
        bool primer = true;
        for (int l = 0; l < n; ++l){
            if (out[l]){
                if (primer) {cout << valors[l]; primer = false;}
                else {cout << "," << valors[l];}
            }
        }
        cout << "}" << endl;
    }

    else if (j < n){
        {out[j] = 0; combinacions(n, j+1, valors, out, sum, s, suma_total);}
        {out[j] = 1; combinacions(n, j+1, valors, out, sum + valors[j], s, suma_total);}
    }
}

int main(){
    int s, n;
    cin >> s >> n;
    vector<int> valors(n, 0);
    vector<int> suma_total(n+1, 0);
    suma_total[0] = 0;
    for (int i = 0; i < n ;++i) {int element; cin >> element; valors[i] = element ;suma_total[i+1] = suma_total[i] + element;}
    vector<bool> out(n, false); 
    combinacions(n, 0, valors, out, 0, s, suma_total);
}