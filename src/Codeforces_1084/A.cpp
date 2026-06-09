#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll const MAXN = 2e6;
ll const INF = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == mx) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1ll;
    cin >> t;

    while(t--)
        solve();
}