#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
    }

    auto topo = [&](int n, vector<vector<int> > &g) {
        vector<int> d(n, 0);
        for (int i = 0; i < n; i ++) for (auto j: g[i]) d[j] ++;
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            if (d[i] == 0) q.push(i);
        }
        vector<int> res;
        while (q.size()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for (auto v: g[u]) {
                d[v] --;
                if (d[v] == 0) q.push(v);
            }
        }
        if (res.size() != n) res.clear();
        return res;
    };
}