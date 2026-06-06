#include <bits/stdc++.h>

using namespace std;


void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    int ops = 0;

    while (M != 0) {
        
        int x = N % M;

        M = x;

        ops++;
    }

    cout << ops << endl;
}
//written by GrimFace
//code for A
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}