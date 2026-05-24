#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<ll> dis_sets;
    map<pair<ll, ll>, bool> visited;

    function<void(ll, ll)> dfs = [&](ll remaining, ll S) {
        auto state = make_pair(remaining, S);

        if (visited.count(state))
            return;

        visited[state] = true;

        if (__builtin_popcountll(remaining) == 1) {
            dis_sets.insert(S);
            return;
        }

        vector<int> leaves;

        for (int node = 1; node <= n; node++) {
            if (!(remaining & (1LL << node)))
                continue;

            int deg = 0;

            for (int neighbor : adj[node]) {
                if (remaining & (1LL << neighbor))
                    deg++;
            }

            if (deg <= 1)
                leaves.push_back(node);
        }

        int max_leaf = *max_element(leaves.begin(), leaves.end());

        ll new_S = S | (1LL << max_leaf);

        for (int leaf : leaves) {
            if (leaf == max_leaf)
                continue;

            ll new_rem = remaining ^ (1LL << leaf);

            dfs(new_rem, new_S);
        }
    };

    ll initial = 0;

    for (int i = 1; i <= n; i++) {
        initial |= (1LL << i);
    }

    dfs(initial, 0);

    cout << dis_sets.size() << '\n';
}
//written by Manisha0369
//code for E
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}