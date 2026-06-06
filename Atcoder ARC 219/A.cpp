#include <bits/stdc++.h>
using namespace std;
using ll=long long ;
void solve() {  
    int n, m;
    cin >> n >> m;

    set<string> binary;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        //complements 
        for (char &c : s)
            c = (c == '0' ? '1' : '0');
        binary.insert(s);
    }

    int bits = min(m, 20);

    for (long long mask = 0; mask < (1LL << bits); mask++) {
        string t(m, '0');
        for (int j = 0; j < bits; j++) {
            if (mask & (1LL << j))
                t[j] = '1';
        }
        if (!binary.count(t)) {
            cout << "Yes\n" << t << "\n";
            return; 
        }
    }

    cout << "No\n";
}
//written by GrimFace 
//code for A-Similarity
int main (){
    
solve();
}