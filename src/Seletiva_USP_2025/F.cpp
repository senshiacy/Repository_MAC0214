#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e18;
const int MAXN = 1e6;

int N, M, K;

vector<vector<pair<int, int>>> adj;

void dijkstra(int src) {
    int dist[MAXN + 7];
    for(int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }

    set<pair<int, int>> st;
    st.insert({0, src});
    dist[src] = 0;

    while(not st.empty()) {
        int cur = st.begin()->second;
        st.erase(st.begin());

        for(auto [viz, c] : adj[cur]) {
            if(dist[cur] + c < dist[viz]) {
                st.erase({dist[viz], viz});
                dist[viz] = dist[cur] + c;
                st.insert({dist[viz], viz});
            }
        }
    }

    cout << dist[N] << endl;
}

void solve() {
    cin >> N >> M >> K;

    adj.resize(MAXN);

    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for(int i = 0; i < N; i++) {
        int T;
        cin >> T;

        while(T--) {
            int u, c;
            cin >> u >> c;
            adj[i + 1].push_back({N + u, c});
            adj[N + u].push_back({i + 1, 0});
        }
    }

    dijkstra(1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}