#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    if (!(cin >> H >> W)) return;
    
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    
   
    vector<int> dist(H * W, -1);
    queue<int> q;
    
    
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
   
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (grid[r][c] == '.') {
                bool has_black = false;
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                        if (grid[nr][nc] == '#') {
                            has_black = true;
                            break;
                        }
                    }
                }
                if (has_black) {
                    dist[r * W + c] = 0;
                    q.push(r * W + c);
                }
            }
        }
    }
    
   
    if (q.empty()) {
        for (int r = 0; r < H; ++r) {
            cout << string(W, '.') << "\n";
        }
        return;
    }
    
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int r = u / W;
        int c = u % W;
        
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                int v = nr * W + nc;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    for (int r = 0; r < H; ++r) {
        string out(W, '.');
        for (int c = 0; c < W; ++c) {
            if (dist[r * W + c] % 2 == 1) {
                out[c] = '#';
            }
        }
        cout << out << "\n";
    }
}
//written by GrimFace
//code for D
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}