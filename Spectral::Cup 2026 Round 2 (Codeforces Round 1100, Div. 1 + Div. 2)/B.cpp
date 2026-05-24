#include <bits/stdc++.h>
using namespace std;
using ll= long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    
    ll S = 0, sumMins = 0, bestMin = 0;
    for (int i = 0; i < n; i++) {
        S += a[i] + b[i];
        sumMins += min(a[i], b[i]);
        bestMin = max(bestMin, min(a[i], b[i]));
    }
    
    cout << S - sumMins + bestMin << "\n";
}
//written by Manisha0369
//code for B
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}