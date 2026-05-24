#include <bits/stdc++.h>
using namespace std;

const long long NEG_INF = -1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<array<long long, 2>> dp(n + 1);
    vector<array<int, 2>> choice(n + 1);
    dp[0] = {0LL, 0LL};
    
    for (int j = 1; j <= n; j++) {
        for (int p = 0; p < 2; p++) {
            long long contrib = (p == 0 ? a[j] : -a[j]);
            long long val0 = contrib + dp[j-1][p];
            long long val1 = NEG_INF;
            if (a[j] > 0) val1 = -contrib + dp[j-1][1-p];
            
            if (val0 >= val1) {
                dp[j][p] = val0;
                choice[j][p] = 0;
            } else {
                dp[j][p] = val1;
                choice[j][p] = 1;
            }
        }
    }
    
    vector<int> ops;
    int p = 0;
    for (int j = n; j >= 1; j--) {
        if (choice[j][p] == 1) {
            ops.push_back(j);
            p = 1 - p;
        }
    }
    reverse(ops.begin(), ops.end());
    
    cout << ops.size() << "\n";
    for (int i = 0; i < (int)ops.size(); i++) {
        cout << ops[i];
        if (i + 1 < (int)ops.size()) cout << " ";
    }
    if (!ops.empty()) cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}