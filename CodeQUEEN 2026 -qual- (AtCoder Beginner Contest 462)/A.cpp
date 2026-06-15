#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const int MOD =1e+9;

// written by  GrimFace 
// code for A


string solve(string S) {
    string res = "";
    copy_if(S.begin(), S.end(), back_inserter(res), ::isdigit);
    return res;
}

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}