#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
vector<int> v[N];
//written by  GrimFace 
//code for F
const ll MOD = 998244353;

vector<ll> divs;
ll ans = 0;
vector<ll> fact;
 
void pre_fact(int mx) {
    fact.resize(mx + 1);
    fact[0] = 1;
    for (int i = 1; i <= mx; i++) {
        fact[i] = (fact[i-1] * (ll)i) % MOD;
    }
}
 
void dfs(long long  rem, long long  min_d, vector<ll>& sub) {
    if (rem == 1) {
        ll se = 0;
        for (ll d : sub) {
            se = (se + d) % MOD;
        }
        
        int k = sub.size();
      
        ll c1 = (se * fact[k]) % MOD;
        ans = (ans + c1) % MOD;
        
  
    ll sc1 = (se + 1) % MOD;
        ll c2 = (sc1 * fact[k + 1]) % MOD;
        ans = (ans + c2) % MOD;
        
        return;
    }
    
    for (ll d : divs) {
        if (d == 1) continue;
        if (d < min_d) continue;
        if (d > rem) break;
        if (rem % d == 0) {
            sub.push_back(d);
            dfs(rem / d, d + 1, sub);
            sub.pop_back();
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    pre_fact(200);
    
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            divs.push_back(i);
            if (i != N / i) {
                divs.push_back(N / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    
    vector<ll> sub;
    dfs(N, 2, sub);
    
    cout << ans << "\n";
    return 0;
}
 