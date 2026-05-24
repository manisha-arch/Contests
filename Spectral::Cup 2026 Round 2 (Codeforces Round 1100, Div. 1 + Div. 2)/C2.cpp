#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
const long long NEG_INF = -1e18;


   
void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<ll> pre(n), suf(n + 1);
    pre[0] = abs(a[0]);
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + abs(a[i]);
    
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    ll best = suf[0];
    int idx = -1;
    for (int i = 1; i < n; i++){
        if (a[i] > 0){
            ll point = pre[i - 1] + suf[i + 1] - a[i];
            if (point > best){
                best = point;
                idx = i;
            }
        }
    }

    if (idx == -1){
        cout << "0\n";
        return;
    }

    vector<int> want ;
    for (int i = idx - 1; i >= 0; i--){
        if (want.size() & 1)
            a[i] = -a[i];
        if (a[i] > 0)
            want.push_back(i);
    }
    want.push_back(idx);

    cout << want.size() << "\n";
    for (int i = 0; i < want.size(); i++)
        cout << want[i] + 1 << " \n"[i == want.size() - 1];
}
//written by Manisha0369
//code for C2
/// @return 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}


