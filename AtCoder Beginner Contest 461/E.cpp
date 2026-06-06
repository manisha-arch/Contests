#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
vector<int> v[N];
//written by  GrimFace 
//code for E


int n, q;
vector<int> br, bc;
vector<int> lr, lc;
int cr = 0, cc = 0;
ll p = 0;

void upd(vector<int>& b, int i, int v) {
    for (; i <= q; i += i & -i) b[i] += v;
}

int qry(vector<int>& b, int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += b[i];
    return s;
}

void solve() {
    cin >> n >> q;
    br.assign(q + 1, 0);
    bc.assign(q + 1, 0);
    lr.assign(n + 1, 0);
    lc.assign(n + 1, 0);
    cr = 0; cc = 0; p = 0;

    for (int i = 1; i <= q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (lr[x]) {
                p -= qry(bc, lr[x] - 1);
                upd(br, lr[x], -1);
            } else cr++;
            lr[x] = i;
            p += qry(bc, i - 1);
            upd(br, i, 1);
        } else {
            if (lc[x]) {
                p -= (cr - qry(br, lc[x]));
                upd(bc, lc[x], -1);
            } else cc++;
            lc[x] = i;
            p+= (cr - qry(br, i));
            upd(bc, i, 1);
        }
        cout << (ll)cr * (n - cc) + p<< "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}