#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
   
    auto prefix_2d = [](vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int> > res;
        res.assign(n, vector<int>(m, 0))
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                res[i][j] = a[i][j];
                if (i >= 1) res[i][j] += res[i-1][j];
                if (j >= 1) res[i][j] += res[i][j-1];
                if (i >= 1 and j >= 1) res[i][j] -= res[i-1][j-1];
            }
        }
        return res;
    };

    ios::sync_with_stdio(false);
    cout.tie(0);
}
