#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6 + 10;

void solve() {
    int N; cin >> N;
    vector<int> freq(MAXN, 0);
    for(int i = 0; i < N; i++) {
        int p;
        cin >> p;
        freq[p]++;
    }

    vector<bool> vis(MAXN, false);
    map<int, int> cnt;
    for(ll i = 2; i < MAXN; i++) {
        if(!vis[i]) {
            for(ll j = i; j < MAXN; j+=i) {
                cnt[i] += freq[j];
                vis[j] = true;
            }
        }
    }

    ll mx = 0, resp = 0;
    for(auto [p, c] : cnt) {
        if(mx < (ll) c) {
            mx = c;
            resp = p;
        }
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}