#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

const ll MAXN = 1e6 + 100;
const ll INF = 1e18;

void solve() {
    int N, D;
    cin >> N >> D;

    vector<pll> vals(N);
    for(int i = 0; i < N; i++) {
        cin >> vals[i].first >> vals[i].second;
    }

    sort(vals.begin(), vals.end());

    int r = -1, mx_val = 0, val = 0, resp = 0;
    vector<ll> melhor(N, 0);
    for(int l = 0; l < N; l++) { // O(N)
        while(r + 1 < N && vals[r + 1].first - vals[l].first <= D) { // O(N)
            val += vals[r + 1].second;
            r++;
            melhor[r] = (r > 0) ? max(melhor[r-1], (ll) val) : val; // A melhor soma que termina ATÉ r
        }
        resp = max((l > 0) ? (ll) val + melhor[l - 1] : val, (ll) resp);
        val -= vals[l].second;
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}