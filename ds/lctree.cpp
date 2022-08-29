typedef long long ll;
const ll inf = 2e18;

struct Nod {
    Nod* lson;
    Nod* rson;
    ll k, b;
    Nod(){}
    Nod(ll k, ll b):k(k),b(b),lson(nullptr),rson(nullptr){}
} nod[N * 63]; 
int tot_size = 0;
Nod* root;

void init() {
    root = nullptr;
    tot_size = 0;
}

void update(Nod* &rt,int l,int r,ll k,ll b){
    if (!rt) {
        nod[++tot_size] = Nod(k, b);
        rt = &nod[tot_size];
        return;
    }
    int m = (l+r)>>1;
    if ((rt->k)*m + (rt->b) <= k*m + b) {
        swap(rt->k, k);
        swap(rt->b, b);
    }   
    if (l==r) return;
    if (k < rt->k) {
        update(rt->lson,l,m,k,b);
    } else {
        update(rt->rson,m+1,r,k,b);
    }
}

ll query(Nod*rt,int l,int r, int pos) {
    if(!rt) return -inf;
    ll ans=(rt->k) * pos + (rt->b);
    if(l==r) return ans;
    int m = (l+r)>>1;
    if (pos <= m) 
        ans = max(ans,query(rt->lson,l,m,pos));
    else 
        ans = max(ans, query(rt->rson,m+1,r,pos));
    return ans;
}
