#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const int MOD =1e+9;

// written by  GrimFace 
// code for E

ll solve(ll a, ll b, ll x, ll y) {
    x = abs(x);
    y = abs(y);
    
    ll tot = x + y;
    
    if (tot == 0) {
        return 0;
    }
    
    ll odd = (tot + 1) / 2;
    ll evn = tot / 2;
    
    ll c1, c2;
    
    if (a <= b) {
        ll ho = min(x, odd);
        ll he = x - ho;
        ll ve = min(y, evn);
        ll vo = y - ve;
        c1 = ho * a + he * b + vo * b + ve * a;
    } else {
        ll he = min(x, evn);
        ll ho = x - he;
        ll vo = min(y, odd);
        ll ve = y - vo;
        c1 = ho * a + he * b + vo * b + ve * a;
    }
    
    if (b <= a) {
        ll vo = min(y, odd);
        ll ve = y - vo;
        ll he = min(x, evn);
        ll ho = x - he;
        c2 = ho * a + he * b + vo * b + ve * a;
    } else {
        ll ve = min(y, evn);
        ll vo = y - ve;
        ll ho = min(x, odd);
        ll he = x - ho;
        c2 = ho * a + he * b + vo * b + ve * a;
    }
    
    return min(c1, c2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << solve(a, b, x, y) << "\n";
    }
    
    return 0;
}




