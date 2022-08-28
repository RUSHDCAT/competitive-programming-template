#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

struct SegmentTree {
    vector<ll> sum, lz;
    void build(int n) {
        sum.assign(n * 4 + 1, 0);
        lz.assign(n * 4 + 1, 0);
    }
    void pushdown(int rt) {
        
    }
    void update(int l, int r, int rt, int L, int R, int x) {
        if (L <= l && r <= R) {
            sum[rt] += x; 
            return;
        }
        int mid = (l + r) >> 1;
        if (L <= mid) update(l, mid, rt<<1, L, R);
        if (R  > mid) update(mid+1, r, rt<<1|1, L, R);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }
    ll query(int l, int r, int rt, int L, int R) {
        if (L <= l && r <= R) {
            return sum[rt];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
}