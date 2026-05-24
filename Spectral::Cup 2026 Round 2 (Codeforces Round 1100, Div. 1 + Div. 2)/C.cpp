#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    
    vector<int> want(n + 1, 0);
    for (int i = 0; i < n; i++)
        want[i] = (a[i] > 0) ? 1 : 0;
    
    
    vector<int> ops;
    for (int i = 0; i < n; i++)
        if (want[i] ^ want[i + 1])
            ops.push_back(i + 1);
    
    
    sort(ops.rbegin(), ops.rend());
    
    cout << ops.size() << "\n";
    for (int x : ops) cout << x << " ";
    cout << "\n";
}
//written by Manisha0369
//code for C
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}