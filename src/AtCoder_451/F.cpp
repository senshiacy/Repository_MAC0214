// Attempt

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long
#define endl '\n'

ll const MAXN = 2e5 + 10;

array<int, MAXN> color; // 0 if black, else 1
array<int, MAXN> compColor;
vector<vector<int>> adj;

// DSU
class DSU {
    private:
        array<int, MAXN> sz;
        array<int, MAXN> ps;
        int N; // number of components

    public:
        DSU(int N) {
            this->N = N;
            for(int i = 1; i <= N; i++) {
                this->sz[i] = 1;
                this->ps[i] = i;
            }
        }
        int find(int a) { // Compression
            vector<int> ms;
            while(a != this->ps[a]) { // Here is the root of comp
                ms.push_back(a);
                a = this->ps[a];
            }
            for(int m : ms) {
                this->ps[m] = a;
            }
            return a;
        }
        void join(int a, int b) {
            // Compression
            int pa = this->find(a);
            int pb = this->find(b);

            if(pa == pb) return;

            if(this->sz[pa] < this->sz[pb]) {
                this->ps[pa] = pb;
                this->sz[pb] += this->sz[pa];
            }
            else {
                this->ps[pb] = pa;
                this->sz[pa] += this->sz[pb];                
            }
        }
        bool sameComponent(int a, int b) {
            return this->find(a) == this->find(b);
        }
        int getSZ(int a) {
            return this->sz[this->find(a)];
        }
};

vector<bool> vis;
int black;
void reflip(int u, int col) {
    vis[u] = true;
    color[u] = col;
    if(color[u] == 0) {
        black++;
    }
    for(auto v : adj[u]) {
        if(!vis[v]) {
            reflip(v, (col + 1) % 2);
        }
    }
}

void solve() {
    /**
     * Inicialmente, todas as N componentes são brancas
     */

    int N, Q;
    cin >> N >> Q;
    bool isValid = true;
    int ans = 0;
    vis.resize(N + 1, false);
    adj.resize(N + 1, vector<int>());

    for(int i = 1; i <= N; i++) {
        color[i] = 1;
        compColor[i] = 0;
    }
    DSU dsu(N);

    while(Q--) {
        int u, v;
        cin >> u >> v;

        // Edges
        adj[u].push_back(v);
        adj[v].push_back(u);

        if(!isValid) {
            cout << -1 << endl;
            continue;
        }

        //cout << u << " " << v << endl;
        
        // Is u and v in the same component?
        if(dsu.sameComponent(u, v)) {
            //cout << "Mesma comp: " << u << " " << color[u] << " " << v << " " << color[v] << endl;
            if(color[u] == color[v]) {
                // In a component, we couldn't have a odd cycle
                isValid = false;
                cout << -1 << endl;
            }
            else {
                cout << ans << endl;
            }
        }
        else {
            int pu = dsu.find(u);
            int pv = dsu.find(v);

            if(color[u] != color[v]) {
                dsu.join(u, v);
                int w = dsu.find(u);
                compColor[w] = compColor[pu] + compColor[pv];
                cout << ans << endl;
            }
            else {
                // Reflip all comps
                fill(vis.begin(), vis.end(), false);
                int szu = dsu.getSZ(u);
                int szv = dsu.getSZ(v);
                black = 0;
                if(szu < szv) {
                    reflip(u, (color[u] + 1) % 2);
                    ans = ans - compColor[pu] + black;
                    dsu.join(u, v);
                    int w = dsu.find(u);
                    compColor[w] = compColor[pv] + black;
                }
                else {
                    reflip(v, (color[v] + 1) % 2);
                    ans = ans - compColor[pv] + black;
                    dsu.join(u, v);
                    int w = dsu.find(u);
                    compColor[w] = compColor[pu] + black;
                }
                cout << ans << endl;
            }
        }

        /*
        cout << "Coisas: " << endl;
        for(int i = 1; i <= N; i++) {
            cout << dsu.find(i) << " ";
        }
        cout << endl;
        for(int i = 1; i <= N; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
        cout.flush();
        */
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}