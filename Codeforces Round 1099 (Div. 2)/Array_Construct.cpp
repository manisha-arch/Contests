#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    for (int i = n + 1; i <= 2 * n; i++) {
        cout << i;
        if (i < 2 * n) cout << " ";
    }
    cout << "\n";
}
//written by Manisha0369
//code for A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}