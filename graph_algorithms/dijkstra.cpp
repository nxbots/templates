#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back

const ll infLL = 9000000000000000000;
const int mx = 1e5+123;
vector<pii> adj[mx];
ll dist[mx];

void dijkstra(int s, int n) {
    for(int i = 0; i <= n; i++) dist[i] = infLL; /// initilization
    dist[s] = 0; /// initilizing source distance
    priority_queue < pll, vector<pll>, greater<pll> > pq;
    pq.push({0, s}); /// pushing source in queue

    while(!pq.empty()) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if(dist[u] < curD) continue; // important

        for(auto p : adj[u]) {
            int v = p.F;
            ll w = p.S;
            if(curD + w < dist[v]) { // relax operation
                dist[v] = curD + w;
                pq.push ({dist[v], v});
            }
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({ v, w });
        adj[v].pb({ u, w });
    }
    dijkstra(1, n);
    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
}
