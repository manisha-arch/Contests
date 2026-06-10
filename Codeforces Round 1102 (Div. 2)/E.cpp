#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 using ll = long long;


#pragma GCC optimize("O3")

/*
CF Round 1102- Div. 2 
*/
//written by  GrimFace 
//code for E
int n;
vector<ll> a;
vector<int> p;
vector<int> u;  
ll res = 0;
 
inline bool chk(int i) {
    int v = p[i];
    int l = 0;
    
    for (int j = i - 1; j >= 0 && p[j] > v; j--) l++;
    
    if (a[i] % (l + 1) != 0) return false;
    
    long long r_f = a[i] / (l + 1);
    int r = r_f - 1;
    
    return r >= 0 && r <= n - i - 1;
}
 
void dfs(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            int v = p[j];
            int l = 0, r = 0;
            
            for (int k = j - 1; k >= 0 && p[k] > v; k--) l++;
            for (int k = j + 1; k < n && p[k] > v; k++) r++;
            
            if ((ll)(l + 1) * (r + 1) != a[j]) return;
        }
        res++;
        return;
    }
    
    for (int v = 1; v <= n; v++) {
        if (!u[v]) {
            p[i] = v;
            u[v] = 1;
            
            if (chk(i)) dfs(i + 1);
            
            u[v] = 0;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        a.assign(n, 0);
        p.assign(n, 0);
        u.assign(n + 1, 0);
        res = 0;
        
        for(int i = 0; i < n; i++) cin >> a[i];
        
        dfs(0);
        cout << res << "\n";
    }
    
    return 0;
}