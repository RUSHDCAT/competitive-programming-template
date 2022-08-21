#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s; 
    s--;
    vector<ll> dis(n, inf); 
    vector< vector<pair<int,int> > > g(n);
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        g[u].push_back({v, w});
        //g[v].push_back({u, w});
    }
    
    auto dijkstra = [&](int src) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> q;
        q.emplace(0, src);
        dis[src] = 0;
        while (not q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (d > dis[u]) continue;
            for (auto [v, w]: g[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    q.emplace(dis[v], v);
                }
            }
        }
    };
    dijkstra(s);
    for (int i = 0; i < n; i ++) cout << dis[i] << " ";

}