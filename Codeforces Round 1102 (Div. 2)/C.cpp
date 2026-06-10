#include <bits/stdc++.h>
using namespace std;
using ll = long long;





const int MOD =1e+9;
/*
CF Round 1102- Div. 2 
*/
//written by  GrimFace 
//code for A


void solve(){
 int n;
    cin >> n;
    vector<ll> h(n);
    for (auto& x : h) cin >> x;


    for (int l = 0; l < n; l++) {
    vector<ll> cw_max(n, 0), ccw_max(n, 0);
        for (int k = 1; k < n; k++) {
            cw_max[k]  = max(cw_max[k-1],  h[(l - k + n * 2) % n]);
            ccw_max[k] = max(ccw_max[k-1], h[(l + k - 1) % n]);
        }

        ll ans = 0;
 for (int k = 1; k < n; k++) {
            ans += min(cw_max[n - k], ccw_max[k]);
        }

        cout << ans;
        if (l < n - 1) cout << ' ';
    }
    cout << '\n';
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}