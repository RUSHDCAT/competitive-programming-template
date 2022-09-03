#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000 + 10;

namespace DCC {
    vector<int> g[N], dcc[N];
    int times = 0;
    int dfn[N], low[N], stk[N], cut[N], top, dcc_cnt, root;
    void init(int n) {
        times = top = dcc_cnt = root = 0;
        for (int i = 0; i <= n; i ++) {
            dfn[i] = low[i] = stk[i] = cut[i] = 0;
            dcc[i].clear();
        }
    }
    void tarjan(int u) {
        dfn[u] = low[u] = ++times;
        stk[++top] = u;
        if (u == root and g[u].size() == 0) {
            dcc_cnt ++;
            dcc[dcc_cnt].push_back(u);
            return;
        }
        int cnt = 0;
        for (auto v: g[u]) {
            if (! dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
                if (dfn[u] <= low[v]) {
                    cnt ++;
                    if (cnt > (u==root)) 
                        cut[u] = true;
                    ++ dcc_cnt;
                    int y;
                    do {
                        y = stk[top--];
                        dcc[dcc_cnt].push_back(y);
                    } while (y != v);
                    dcc[dcc_cnt].push_back(u);
                }
            } else low[u] = min(low[u], dfn[v]);
        }
    }
    void build(int n) {
        init(n);
        for (root = 1; root <= n; root ++) if (! dfn[root]) {
            tarjan(root);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        if (u != v) {
            DCC::g[u].push_back(v);
            DCC::g[v].push_back(u);
        }
    } 
    DCC::build(n);
    cout << DCC::dcc_cnt << "\n";
    for (int i = 1; i <= DCC::dcc_cnt; i ++) {
        cout << DCC::dcc[i].size();
        for (auto x: DCC::dcc[i]) {
            cout << " " << x;
        }
        cout << "\n";
    }
}