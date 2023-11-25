const int N = 2e5+9;
int a[N];

struct ST {
    #define lc (node<<1)
    #define rc ((node<<1)+1)
    ll t[4*N];
    ST() {
        memset(t, 0, sizeof t);
    }
    inline ll combine(ll a, ll b) { //change here
        return a+b;
    }
    inline void pull(int node) { //change here
        t[node] = t[lc]+t[rc];
    }
    void build(int node, int b, int e) {
        if(b == e) {
            t[node] = a[b];
            return;
        }
        int mid = (b+e)>>1;
        build(lc, b, mid);
        build(rc, mid+1, e);
        pull(node);
    }
    void update(int node, int b, int e, int i, int x) {
        if(i < b || i > e) return;
        if(b == e && b == i) {
            t[node] = x;
            return;
        }
        int mid = (b+e)>>1;
        update(lc, b, mid, i, x);
        update(rc, mid+1, e, i, x);
        pull(node);
    }
    ll query(int node, int b, int e, int i, int j) {
        if(j < b || i > e) return 0; //change here
        if(b >= i && e <= j) return t[node];
        int mid = (b+e)>>1;
        return combine(query(lc, b, mid, i, j),
                       query(rc, mid+1, e, i, j));
    }
}t;
