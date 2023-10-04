#include <iostream>
#include <vector>
using namespace std;

void combinacions(int n, int j, 
const vector<int>& valors, vector<bool>& out, int sum, int s){
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
        {out[j] = 0; combinacions(n, j+1, valors, out, sum, s);}
        {out[j] = 1; combinacions(n, j+1, valors, out, sum + valors[j], s);}
    }
}

int main(){
    int s, n;
    cin >> s >> n;
    vector<int> valors(n);
    for (int& element : valors) cin >> element;
    vector<bool> out(n, false); 
    combinacions(n, 0, valors, out, 0, s);
}