
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#pragma GCC optimize("O3")
const int MOD =1e+9;
/*
CF Round 1102- Div. 2 
*/
//written by  GrimFace 
//code for D

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
typedef int ii;
 
void solve (){
    
    
   
         int n, k;
    cin >> n >> k;
    
    string s, z;
    cin >> s >> z;
    
    ll t = (1LL << k) + 1;
    ll res = 0;
    
   
    for (int bit = 0; bit < n; bit++) {
        int b1 = s[bit] - '0';
        int b2 = z[bit] - '0';
        
        ll on;
        if (b1 == b2) {
      
            on = b1 ? t : 0;
        } else {
            
            on = 1LL << (k - 1);
            if (b1 == 1) on++;
            if (b2 == 1) on++;
        }
        
        ll zeros = t - on;
        res += on * zeros;
    }
    
    cout << res << "\n";
      
    }
    
   

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ii t;
    cin >> t;
    
    while(t--) {
       solve();
    }
    
    return 0;
}
 