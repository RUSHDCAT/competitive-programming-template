#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class KThMinMax {
  public:
    multiset<int> low, high;
    ll sum = 0;
    int k;
    KThMinMax<T>(int k):k(k),sum(0) {
        low.clear();
        high.clear();
    }
    void insert(int x) {
        low.insert(x); 
        sum += x;
        if (low.size() > k) {
            int d = *low.rbegin();
            sum -= d;
            high.insert(d);
            low.erase(low.find(d)); 
        }
    }
    void erase(int x) {
        if (low.find(x) != low.end()) {
            sum -= x;
            low.erase(low.find(x));
            if (low.size() < k and high.size() > 0) {
                int x = *high.begin();
                high.erase(high.find(x));
                low.insert(x);
                sum += x;
            }
        } else if (high.find(x) != high.end()) {
            high.erase(high.find(x));
        }
    }
};

int main() {
    KThMinMax<int> s(4);
    for (int i = 1; i <= 10; i ++) {
        s.insert(i);
    }
    cout << s.sum << "\n";
    s.erase(4);
    cout << s.sum << "\n";
}
