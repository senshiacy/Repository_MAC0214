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

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool invert = false;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            invert = true;
        }
    }

    if(invert) {
        cout << 1 << endl;
    }
    else {
        cout << n << endl;
    }
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