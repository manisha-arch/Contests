#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const int MOD =1e+9;

// written by  GrimFace 
// code for D
void solve(){
  int N, D;
    cin >> N >> D;

    const int MAXT = 1'000'000;
    vector<int> d(MAXT + 3, 0);

    for (int i = 0; i < N; i++) {
        int S, T;
        cin >> S >> T;

        int L = S;
        int R = T - D;

        if (L <= R) {
            d[L]++;
            d[R + 1]--;
        }
    }

    ll ans = 0;
    int a = 0;

    for (int x = 1; x <= MAXT; x++) {
        a+= d[x];
        ans += 1LL * a * (a - 1) / 2;
    }

    cout << ans << '\n';

 
}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   solve();
   return 0;
}