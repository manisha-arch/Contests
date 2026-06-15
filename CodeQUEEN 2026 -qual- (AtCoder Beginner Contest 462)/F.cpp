#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    // cost[i] = chars to replace to make s[i..i+2] = ABC
    vector<int> cost(n, INT_MAX);
    for (int i = 0; i + 2 < n; i++) {
        int c = 0;
        if (s[i] != 'A') c++;
        if (s[i+1] != 'B') c++;
        if (s[i+2] != 'C') c++;
        cost[i] = c;
    }

    const ll INF = 1e18;
    // dp[j] = min cost to have added j new ABCs, last placed at some position
    // need to track last placed position to avoid overlap

    // dp[i][j] = min cost up to position i, added j new ABCs, 
    //            where we either placed or didn't place at i
    // transition: 
    //   don't place at i: dp[i][j] = dp[i-1][j]
    //   place at i (cost>0, no overlap with existing ABC, no overlap with last placed):
    //     dp[i][j] = min over valid prev of dp[prev][j-1] + cost[i]
    //     where prev < i-2 (non-overlapping)

    // To handle existing ABCs blocking: if cost[i]==0, we can't place anything 
    // at i-2,i-1,i+1,i+2 as new (they'd overlap)
    // Actually if cost[i]==0, it's already ABC, placing at i again doesn't add new
    // We only place at positions where cost>0

    // Mark positions blocked by existing ABCs
    vector<bool> blocked(n, false);
    for (int i = 0; i + 2 < n; i++) {
        if (cost[i] == 0) {
            for (int j = max(0, i-2); j <= min(n-3, i+2); j++) {
                blocked[j] = true;
            }
        }
    }

    // dp[i][j]: min cost considering first i positions, j new ABCs added
    // i from 0..n-2 (valid start positions), j from 0..K
    vector<vector<ll>> dp(n, vector<ll>(k+1, INF));
    
   
  
    int m = n - 2; // valid positions: 0..m-1
   
    vector<vector<ll>> f(m+1, vector<ll>(k+1, INF));
    f[0][0] = 0; // before any position

    // f[i][j] = min cost considering positions 0..i-1, placed j new
    // place at position i-1: f[i][j] = f[max(0,i-3)][j-1] + cost[i-1] if valid
    // skip position i-1:     f[i][j] = f[i-1][j]

    // redefine: g[i][j] = min cost, positions 0..i processed, j placed
    // g[-1][0] = 0 (sentinel)
    // g[i][j] = min(g[i-1][j], // skip i
    //               g[i-3][j-1] + cost[i]) if i valid placement
    // where g[i] for i<0 = 0 if j==0 else INF

    auto getg = [&](vector<vector<ll>>& g, int i, int j) -> ll {
        if (i < 0) return j == 0 ? 0 : INF;
        return g[i][j];
    };

    vector<vector<ll>> g(m, vector<ll>(k+1, INF));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            // skip
            g[i][j] = getg(g, i-1, j);
            // place at i
            if (j > 0 && !blocked[i] && cost[i] > 0) {
                ll prev = getg(g, i-3, j-1);
                if (prev != INF) {
                    g[i][j] = min(g[i][j], prev + cost[i]);
                }
            }
        }
    }

    ll ans = g[m-1][k];
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}