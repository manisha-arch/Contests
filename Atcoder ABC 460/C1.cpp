#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0; 
    int j = 0; 
    int combs = 0;

 
    while (i < N && j < M) {
        if (B[j] <= 2LL * A[i]) {
          
            combs++;
            i++;
            j++;
        } else {
           
            i++;
        }
    }

    
    cout << combs << "\n";
}
//written by GrimFace
//code for C
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}