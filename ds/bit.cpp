#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Bit {
    vector<ll> a;
    Bit(){}
    Bit(int n) {
        a.assign(n + 1, 0ll);
    }
    void add(int p, ll x) {
        while (p < a.size()) {
            a[p] += x;
            p += p&(-p);
        }
    }
    ll sum(int p) {
        ll ans = 0;
        while (p > 0) {
            ans += a[p];
            p -= p&(-p);
        }
        return ans;
    }
} bit;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    bit = Bit(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i], bit.add(i + 1, a[i]);

    while (q --) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            bit.add(x, y);
        } else {
            cout << bit.sum(y) - bit.sum(x - 1) << "\n";
        }
    }
}