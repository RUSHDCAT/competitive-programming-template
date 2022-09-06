#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    using VT = vector<T>;
    using VVT = vector<VT>;
    using func_type = function<T(const T&,const T&)>;

    VVT ST;
    static T default_func(const T &t1, const T &t2) {
        return max(t1, t2);
    }
    func_type op;

  public:
    SparseTable<T>(const vector<T>&v, func_type func = default_func) {
        op = func;
        int len = v.size(), l1 = ceil(log2(len)) + 1;
        ST.assign(len, VT(l1, 0));
        for (int i = 0; i < len; i ++) {
            ST[i][0] = v[i];
        }    
        for (int j = 1; j < l1; j ++) {
            int pj = (1<<(j-1));
            for (int i = 0; i + pj < len; i ++) {
                ST[i][j] = op(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
            }
        }
    }
    T query(int l,int r) {
        int lt = r - l + 1;
        int q = ceil(log2(lt)-1);
        return op(ST[l][q], ST[r-(1<<q)+1][q]);
    }
};

int main() {
    vector<int> a = {1,1,4,5,1,4};
    SparseTable<int> st(a);
    cout << st.query(0,3) << "\n";
}
