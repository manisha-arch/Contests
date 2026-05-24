#include <bits/stdc++.h>
using namespace std;

using ll= long long;
bool check(int [] arr, int n){
    for (int i = 1; i < n; i++) {
    if (arr[i] != arr[0]) return false;
}
return true;
}
int solve (){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            a[i]=a[i]/2;
            cnt++;


        }else{
            a[i]=a[i]-1;
            cnt++;
        }
    }
    if(check(a,n)){
        return cnt;
else{
    return 0;
}

}
//written by Manisha0369
//code for C
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // solve here
    return 0;
}
