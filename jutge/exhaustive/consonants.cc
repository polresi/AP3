#include <iostream>
#include <vector>
using namespace std;

void permuta(int n, const vector<char>& c, const vector<char>& v, 
            vector<bool>& usatc, vector<bool>& usatv,
            int idx, vector<char>& out){
    if (idx == 2*n){
        for (char element : out) cout << element;
        cout << endl;
        return;
    }
    const vector<char>& llista = (idx%2 ==0 ? c:v); 
    vector <bool>& usat = (idx%2 ==0 ? usatc : usatv);
    for (int i = 0; i < n; i++){
        if (not usat[i]){
            out[idx] = llista[i];
            usat[i] = true;
            permuta(n, c, v, usatc, usatv, idx +1, out);
            usat[i] = false;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<char> c(n), v(n);
    for (char& ci: c) cin >> ci;
    for (char& vi: v) cin >> vi;
    vector<bool> usatc(n, false);
    vector<bool> usatv(n, false);
    vector<char> out(2*n);
    permuta(n ,c,v,usatc,usatv, 0, out);
}