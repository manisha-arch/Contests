#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
CF Round 1102- Div. 2 
*/
//written by  GrimFace 
//code for G
//basic template for cp 
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second


void solve() {
     int n;
    if (!(cin >> n)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
   vector<bool> w(n + 2, false);
    
 
    vector<int> lo(n + 3, 0);

    w[n + 1] = false;
    lo[n + 1] = 1;

    for (int i = n; i >= 1; --i) {
    
    
        long long R = min((long long)n + 1, (long long)i + 1 + a[i]);

        if (R == n + 1) {
        
            w[i] = true;
        } else {
          
            int cnt = lo[i + 1] - lo[R + 1];
            w[i] = (cnt > 0);
        }

     
        lo[i] = lo[i + 1] + (w[i] ? 0 : 1);
    }

    cout << (w[1] ? 1 : 2) << '\n';
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
     if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}