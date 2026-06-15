#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

//written by GrimFace 
//code for C
void solve() {
     
     int N;
        cin >> N;
        vector<vector<ll>> A(N, vector<ll>(N));
        ll sum[2] = {0}; 

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++ ) {
                cin >> A[i][j];
                sum[(i+j) % 2] += A[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j) cout << ' ';
                cout << sum[(i+j) % 2];
            }
            cout << '\n';
        }
  
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