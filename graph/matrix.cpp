#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i ++)
            cin >> s[i];
        
        vector<vector<int> > vis(n, vector<int>(m,0));
        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};
        auto in = [&](int x, int y) {
            return x>=0 and x<n and y>=0 and y<m and s[nx][ny]=='*' and vis[nx][ny]==0;
        };
        auto bfs = [&](int x, int y) {
            queue<pair<int,int> > q;
            q.emplace(x, y);
            vis[x][y] = 1;
            while (not q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < dx.size(); i ++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (in(nx, ny)) {
                        q.emplace(nx, ny);
                        vis[nx][ny] = 1;
                    } 
                }
            }
        };
    }
}
