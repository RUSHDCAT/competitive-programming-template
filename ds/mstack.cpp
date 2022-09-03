#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    // prev index j, a[j] > a[i]
    auto build_stk = [](vector<int> a) {
        int n = a.size();
        vector<int> pre(n);
        vector<int> stk;
        for (int i = 0; i < n; i ++) {
            while (stk.size() and a[i] > a[stk.back()]) {
                stk.pop_back();
            }
            pre[i] = stk.size() ? stk.back() : -1;
            stk.push_back(i);
        }
        return pre;
    };

    // calculate k-max
    auto build_que = [](vector<int> a, int k){
        int n = a.size();
        vector<int> q(n), ans(n); 
        int head = 0, tail = 0;
        for (int i = 0; i < n; i ++) {
            // [head, tail)
            while (tail > head and a[i] > a[tail - 1]) -- tail;
            q[tail ++] = i;
            while (q[tail - 1] - q[head] + 1 > k) head ++;
            ans[i] = a[q[head]];
        }
        return ans;
    };

    vector<int> a = {2, 1, 3, 2, 5};
    for (auto x: build_que(a, 3)) {
        cout << x << "\n";
    }
}
