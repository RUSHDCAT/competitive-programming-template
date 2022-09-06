#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
namespace Comb {
    const int N = 200000 + 10;
    ll mpow(ll a, ll x) {
        if (x == 0) return 1;
        ll t = mpow(a, x>>1);
        if (x%2==0) return t*t%mod;
        return t*t%mod*a%mod;
    }
    ll fac[N], inv[N];
    void init() {
        fac[0] = inv[0] = 1;
        for (int i = 1; i < N; i ++) {
            fac[i] = fac[i-1] * i % mod;
            inv[i] = mpow(fac[i], mod - 2);
        }
    }
    ll c(int x, int y) {
        return fac[x] * inv[y] % mod * inv[x-y] % mod;
    }
}

int main() {
    Comb::init();
    std::cout << Comb::c(5, 2) << endl;
}