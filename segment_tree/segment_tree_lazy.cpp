const int N = 5e5+9;
int a[N];
struct ST {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    ll t[4*N], lazy[4*N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    //change this
    inline void push(int node, int b, int e) {
        if(lazy[node] == 0) return;
        t[node] = t[node]+lazy[node]*(e-b+1);
        if(b != e) {
            lazy[lc] = lazy[lc]+lazy[node];
            lazy[rc] = lazy[rc]+lazy[node];
        }
        lazy[node] = 0;
    }
    //change this
    inline ll combine(ll a, ll b) {
        return a+b;
    }
    //change this
    inline void pull(int node) {
        t[node] = t[lc]+t[rc];
    }
    void build(int node, int b, int e) {
        lazy[node] = 0; //change this
        if(b == e) {
            t[node] = a[b];
            return;
        }
        int mid = (b+e) >> 1;
        build(lc, b, mid);
        build(rc, mid+1, e);
        pull(node);
    }
    void upd(int node, int b, int e, int i, int j, ll v) {
        push(node, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[node] += v;
            push(node, b, e);
            return;
        }
        int mid = (b+e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid+1, e, i, j, v);
        pull(node);
    }
    ll query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if(i > e || b > j) return 0; //return null
        if(i <= b && e <= j) return t[node];
        int mid = (b+e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid+1, e, i, j));
    }
}t;

int32_t main() {
    int n, q;
    cin >> n >> q;
    t.build(1, 1, n);
    while(q--) {
        int p, i, j, v;
        cin >> p >> i >> j;
        if(p == 0) {
            cin >> v;
            t.upd(1, 1, n, i, j, v);
        }
        else {
            cout << t.query(1, 1, n, i, j) << endl;
        }
    }
}
