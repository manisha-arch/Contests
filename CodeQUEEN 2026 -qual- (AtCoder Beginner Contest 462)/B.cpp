#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// written by  GrimFace 
// code for B

vector<vector<int>> solve(int N, vector<vector<int>>& g) {
    
    vector<vector<int>> rec(N + 1);
    
    
    for (int i = 1; i <= N; i++) {
       
        for (int ret : g[i]) {
          
            rec[ret].push_back(i);
        }
    }
    
  
    for (int i = 1; i <= N; i++) {
        sort(rec[i].begin(), rec[i].end());
    }
    
    return rec;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    
    
    vector<vector<int>> g(N + 1);
    
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        g[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> g[i][j];
        }
    }
    
    vector<vector<int>> res = solve(N, g);
    
   
    for (int i = 1; i <= N; i++) {
        cout << res[i].size();
        for (int s : res[i]) {
            cout << " " << s;
        }
        cout << endl;
    }
    
    return 0;
}