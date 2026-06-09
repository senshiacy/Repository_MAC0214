#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

vector<vector<int>> adj;
/*
vector<vector<int>> rev_adj;

vector<bool> vis;

void dfs(int v, vector<int> &out) {
    vis[v] = true;
    for(auto u : adj[v]) {
        if(!vis[u]) {
            dfs(u, out);
        }
    }
    out.push_back(v);
}

void kosaraju(int N) {
    vector<int> order;
    vis.assign(N + 1, false);
    
    // DFS
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            dfs(i, order);
        }
    }

    // G^{-1}
    for(int i = 1; i <= N; i++) {
        for(auto v : adj[i]) {
            rev_adj[v].push_back(i);
        }
    }

    rev_adj.assign(N + 1, vector<int>());
    vis.assign(N + 1, false);
    reverse(order.begin(), order.end());

    vector<int> roots(N + 1, 0);
    for(auto v : order) {
        if(!vis[v]) {
            vector<int> component;
            dfs(v, component);
        }
    }
}
*/

vector<bool> vis;

int dfs(int v, int cnt) {
    vis[v] = true;
    for(auto u : adj[v]) {
        if(!vis[u])
            cnt = dfs(u, cnt);
    }
    return cnt + 1;
}

void solve() {
    int N, M;
    cin >> N >> M;

    /**
     * N tips de item 1
     */

    adj.resize(N + 1, vector<int>());

    int A, B;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
    }

    vis.assign(N + 1, false);
    int ans = dfs(1, 0);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    //cin >> t;

    while(t--)
        solve();
}