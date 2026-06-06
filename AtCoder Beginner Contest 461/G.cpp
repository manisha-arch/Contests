#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
vector<int> v[N];
//written by  GrimFace 
//code for G
const int MAXN = 5e4 + 5;
const ll MAX_WT = 2026;
 
vector<int> adj[MAXN];
int clr[MAXN];  
int n, m;
 

tuple<bool, int, int> check_bi(int start) {
    queue<int> q;
    q.push(start);
    clr[start] = 0;
    
    int cnt[2] = {0, 0};
    bool is_bi = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt[clr[u]]++;
        
        for (int v : adj[u]) {
            if (clr[v] == -1) {
              
                clr[v] = 1 - clr[u];
                q.push(v);
            } else if (clr[v] == clr[u]) {
                
                is_bi = false;
            }
        }
    }
    
    return make_tuple(is_bi, cnt[0], cnt[1]);
}
 
ll solve() {

    for (int i = 0; i <= n; i++) {
        clr[i] = -1;
    }
    
    ll t_sum = 0;
    
  
    for (int i = 1; i <= n; i++) {
        if (clr[i] == -1) {
            bool is_bi;
            int cnt0, cnt1;
            
            tie(is_bi, cnt0, cnt1) = check_bi(i);
            
            if (is_bi) {
                
                ll cont = MAX_WT * max(cnt0, cnt1);
                t_sum += cont;
            } else {
               
                int comp = cnt0 + cnt1;
                ll cont = (MAX_WT / 2) * comp;
                t_sum += cont;
            }
        }
    }
    
    return t_sum;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << solve() << "\n";
    
    return 0;
}