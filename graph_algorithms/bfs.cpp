vi g[N], dis(N), par(N);
bool vis[N];

queue<int> q;
q.push(1);
vis[1] = true;
dis[1] = 0;
par[1] = -1;
while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v : g[u]) {
        if(!vis[v]) {
            q.push(v);
            par[v] = u;
            vis[v] = true;
            dis[v] = dis[u]+1;
        }
    }
}
