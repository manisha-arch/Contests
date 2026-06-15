#include <bits/stdc++.h>
using namespace std;
using ll = long long;



//const int MOD =1e+9;
/*
CF Round 1102- Div. 2 
*/
//written by  GrimFace 
//code for B
//basic template for cp 
// #define vi vector<int>
// #define vll vector<long long>
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define all(x) (x).begin(), (x).end()
// #define pb push_back
// #define mp make_pair
// #define F first
// #define S second
/*
this is an editorial soln. the intuition was simple all remainder of 12  were palin. but not 10 .
so we used brute force for 10 and next smallest palin. was 22 so we did n-22.
*/

void solve() {
    ll n;
    cin >> n;
   if(n==10){
    cout<<"-1\n";

   }else if(n%12==10){
    cout<<"22 "<<n-22<<"\n";
   }else{
    cout<<n%12<<" "<<n-(n%12)<<"\n";
   }
    
   
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}