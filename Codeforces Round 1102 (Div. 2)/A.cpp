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
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b.rbegin(), b.rend());

   
    ll x = b[0], y = b[1];

    vector<ll> ed;
    ed.push_back(x);
    ed.push_back(y);

    while ((int)ed.size() < n) {
        ll last = ed[ed.size() - 1];
        ll sec_last = ed[ed.size() - 2];
        ll nxt = sec_last % last;
        if (nxt == 0) break;
        ed.push_back(nxt);
    }

    vector<ll> gen = ed;
    sort(gen.rbegin(), gen.rend());

    if (gen == b) {
        cout << x << " " << y << "\n";
    } else {
        cout << "-1\n";
    }
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