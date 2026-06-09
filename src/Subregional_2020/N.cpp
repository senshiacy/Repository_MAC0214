#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 4e7;

ll fast_exp(ll a, ll n) {
    if(n == 0) {
        return 1;
    }

    ll tmp = fast_exp(a, n/2);
    if(n % 2 == 1) {
        return tmp * tmp * a;
    }
    return tmp * tmp;
}

void solve() {
    int M, N, K;
    cin >> M >> N >> K;

    vector<map<ll, ll>> m(M + 1, map<ll, ll>());
    vector<ll> n(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> n[i];
    }
    while(K--) {
        int mnode, nnode, d;
        cin >> mnode >> nnode >> d;
        m[mnode][nnode] += d;
    }

    ll curr = 1;
    vector<bool> vis(MAXN, false);
    vector<ll> ans(M + 1, -1);

    for(ll i = 2; i < MAXN; i++) {
        if(!vis[i]) {
            if(curr <= M) {
                auto [idx, freq] = *m[curr].begin(); // Qualquer um
                if(n[idx] % i == 0) {
                    ans[curr] = i;
                    for(auto [idxn, freqn] : m[curr]) {
                        n[idxn] /= (fast_exp(i, freqn));
                    }
                    curr++;
                }
            }
            else {
                break;
            }
            for(ll j = i * i; j < MAXN; j += i) {
                vis[j] = true;
            }
        }
    }

    for(int i = 1; i <= M; i++) {
        if(ans[i] == -1) {
            auto [idx, freq] = *m[i].begin(); // Qualquer um
            ans[i] = n[idx];
        }
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}