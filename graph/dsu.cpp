#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> par;
    vector<int> sz;
    void init(int n) {
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        sz.resize(n, 1);
    } 
    int find(int x) {
        return par[x] == x ? x: par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            sz[py] += sz[px];
            par[px] = py;
        }
    }
} D; 

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    D.init(n);
    for (int i = 0; i < m; i ++) {
        int q, x, y;
        cin >> q >> x >> y;
        x --, y --;
        if (q == 1) {
            D.unite(x, y);
        } else {
            cout << ((D.find(x) == D.find(y)) ? "Y" : "N") << "\n";
        }
    }
}