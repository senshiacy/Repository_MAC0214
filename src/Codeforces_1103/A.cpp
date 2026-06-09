#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    cout << h[n-1] + 1 - h[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}