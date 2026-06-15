#include <bits/stdc++.h>

using namespace std;


//written by GrimFace 
//code for A
void solve() {
     int n, m;
    cin >> n >> m;

    vector<vector<int>> addL(n+2), remL(n+2);

    for(int j = 0; j < m; j++){
        int l, r;
        cin >> l >> r;
        if(l < r){
            addL[l+1].push_back(l);
            remL[r+1].push_back(l);
        }
    }

    multiset<int> actL;
    vector<int> A(n+1);
    vector<int> cnt(n+2, 0);
    int cur = 1;
    int wL = 1;

    for(int i = 1; i <= n; i++){
        for(int l : addL[i]) actL.insert(l);
        for(int l : remL[i]) actL.erase(actL.find(l));

        int newWL = actL.empty() ? i : *actL.begin();

        while(wL < newWL){
            int v = A[wL];
            cnt[v]--;
            if(cnt[v] == 0 && v < cur) cur= v;
            wL++;
        }

        if(i > 1){
            int v = A[i-1];
            cnt[v]++;
            while(cnt[cur] > 0) cur++;
        }

        A[i] = cur;
    }

    for(int i = 1; i <= n; i++){
        cout << A[i];
        if(i < n) cout << ' ';
    }
    cout << '\n';
   
}


int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
while(t--){
  solve();
}
    
    return 0;
}