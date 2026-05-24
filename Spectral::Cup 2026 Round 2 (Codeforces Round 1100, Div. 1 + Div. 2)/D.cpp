#include <bits/stdc++.h>
using namespace std;

int merge_state(int x, int y) {
    int s = x + y;
    if (s <= 1) return 0;
    return min(2, s - 1);
}

bool reach_two(vector<int>& state) {
    int n = state.size();
    if (n == 1) return state[0] == 2;

    vector<int> left(n), right(n);
    vector<bool> alive(n, true);
    for (int i = 0; i < n; i++) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    right[n - 1] = -1;

    vector<vector<int>> bucket(5);
    for (int i = 0; i + 1 < n; i++) {
        bucket[state[i] + state[i + 1]].push_back(i);
    }

    int alive_count = n;
    int min_bucket = 0;
    while (alive_count > 1) {
        int i = -1;
        while (min_bucket < 5) {
            while (!bucket[min_bucket].empty()) {
                int idx = bucket[min_bucket].back();
                bucket[min_bucket].pop_back();
                if (!alive[idx]) continue;
                int j = right[idx];
                if (j == -1 || !alive[j]) continue;
                int current_sum = state[idx] + state[j];
                if (current_sum != min_bucket) continue;
                i = idx;
                break;
            }
            if (i != -1) break;
            min_bucket++;
        }
        if (i == -1) return false;

        int j = right[i];
        int new_state = merge_state(state[i], state[j]);
        state[i] = new_state;
        alive[j] = false;
        alive_count--;

        int next = right[j];
        right[i] = next;
        if (next != -1) left[next] = i;

        int prev = left[i];
        if (prev != -1) {
            int sum = state[prev] + state[i];
            bucket[sum].push_back(prev);
            if (sum < min_bucket) min_bucket = sum;
        }
        if (next != -1) {
            int sum = state[i] + state[next];
            bucket[sum].push_back(i);
            if (sum < min_bucket) min_bucket = sum;
        }
    }

    int root = -1;
    for (int k = 0; k < n; k++) {
        if (alive[k]) {
            root = k;
            break;
        }
    }
    return (root != -1 && state[root] == 2);
}

bool feasible(int mid, const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> state(n);
    for (int i = 0; i < n; i++) {
        state[i] = (a[i] >= mid) + (b[i] >= mid);
    }
    return reach_two(state);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int lo = 1, hi = 2 * n, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(mid, a, b)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
}
//written by Manisha0369
//code for D

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
