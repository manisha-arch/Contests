#include <bits/stdc++.h>
using namespace std;
using ll= long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    
    cout << (mx - mn + 1) / 2 << "\n";
}
//written by Manisha0369
//code for A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}