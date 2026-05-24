#include <bits/stdc++.h>
using namespace std;
using ll =long long ;
vector<int> compute_failure(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> fail(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j-1];
        if (pattern[i] == pattern[j])
            j++;
        fail[i] = j;
    }
    return fail;
}


int kmpSearch(const vector<int>& text, const vector<int>& pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return 0;
    vector<int> fail = compute_failure(pattern);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = fail[j-1];
        if (text[i] == pattern[j])
            j++;
        if (j == m)
            return i - m + 1;
    }
    return -1;
}

void solve(int num) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

   
    vector<int> text;
    text.reserve(2 * N);
    text.insert(text.end(), A.begin(), A.end());
    text.insert(text.end(), A.begin(), A.end());

    int pos = kmpSearch(text, B);

    string ans;
    if (pos == -1) {
       
        ans = "NO";
    } else {
        int d = pos; 
        if (K == 0) {
            ans = (d == 0) ? "YES" : "NO";
        } else if (K == 1) {
            ans = (d != 0) ? "YES" : "NO";
        } else {
            
            ans = "YES";
        }
    }

    cout << "Case #" << num << ": " << ans << "\n";
}
//written by Manisha0369
//code for A1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}