#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const int MOD =1e+9;

// written by  GrimFace 
// code for C
void solve(){
 int N;
    cin >> N;

    vector<int> YX(N + 1);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        YX[X] = Y;
    }

    int ans = 0;
    int mn = N + 1;  

    for (int x = 1; x <= N; x++) {
        if (YX[x] < mn) {
            ans++;
            mn = YX[x];
        }
    }

    cout << ans << '\n';
}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   solve();
   return 0;
}