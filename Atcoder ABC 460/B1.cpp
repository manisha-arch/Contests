#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long X1, Y1, R1, X2, Y2, R2;
    cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
    
    
    long long d2 = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
    
    long long diff = (R1 - R2) * (R1 - R2);
    long long sum = (R1 + R2) * (R1 + R2);
    
    if (d2 >= diff && d2 <= sum) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
//written by GrimFace 
//code for B
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    
    return 0;
}