#include <bits/stdc++.h>

using namespace std;


//written by GrimFace 
//code for A
void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    
   
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
   
    bool at = true;
    for (int i = 0; i < N; i++) {
        int wc = i + 1;     
        int ca = A[i];        
        int ao = B[ca - 1];  
        
        if (ao != wc) {
            at = false;
            break;
        }
    }
    
    if (at) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}


int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  solve();
    
    return 0;
}