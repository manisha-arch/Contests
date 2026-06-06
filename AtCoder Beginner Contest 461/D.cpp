#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
vector<int> v[N];
//written by  GrimFace 
//code for D
void solve() {
   int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    ll ans = 0;
    vector<int> c(w);
    vector<int> p(w + 1);

    for (int i = 0; i < h; i++) {
        fill(c.begin(), c.end(), 0);
        for (int j = i; j < h; j++) {
            for (int x = 0; x < w; x++) {
                c[x] += s[j][x] - '0';
            }

            p[0] = 0;
            for (int x = 0; x < w; x++) p[x + 1] = p[x] + c[x];

            int l1 = 0, l2 = 0;
            for (int y = 1; y <= w; y++) {
                int tar = p[y] - k;
                while (l1 < y && p[l1] < tar) l1++;
                while (l2 < y && p[l2] <= tar) l2++;
                ans += (l2 - l1);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}