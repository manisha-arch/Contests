#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll= long long ;

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve() {
    ull N, M;
    cin >> N >> M;
    
    ull low = 1;
    ull P = 1; 
    ull ans = 0;
    const ull MOD = 998244353;
    
    
    for (int L = 1; L <= 19; ++L) {
        if (low > N) break;
        
        ull next_low = low * 10;
        ull high = next_low - 1;
        if (high > N) high = N;
        
       
        ull C_L = high - low + 1;
        
       
        P = (P * 10) % M;
        
   
        ull R_L = (P + M - 1) % M;
        ull D_L = M / gcd(M, R_L);
        
        ull valid_x = N / D_L;
        
        valid_x %= MOD;
        ull C_L_mod = C_L % MOD;
        
        ans = (ans + valid_x * C_L_mod) % MOD;
        
        low = next_low;
    }
    
    cout << ans << "\n";
}
//written by GrimFace 
//code for E
int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}