#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
vector<int> v[N];
//written by  GrimFace 
//code for C
void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        int c, x;
        cin >> c >> x;
        v[c].push_back(x);
    }

    vector<int> b, p;
    for (int i = 1; i <= n; i++) {
        if (v[i].empty()) continue;
        sort(v[i].rbegin(), v[i].rend());
        b.push_back(v[i][0]);
        for (int j = 1; j < (int)v[i].size(); j++) p.push_back(v[i][j]);
    }

    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for (int i = 0; i < m; i++) ans += b[i];

    for (int i = m; i < (int)b.size(); i++) p.push_back(b[i]);
    sort(p.rbegin(), p.rend());

    for (int i = 0; i < k - m; i++) ans += p[i];

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}