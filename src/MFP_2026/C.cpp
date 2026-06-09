#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;

void solve() {
    ll X, Y;
    cin >> X >> Y;

    ll v1 = (X - (X % 7))/7 * Y;
    ll v2 = (Y - (Y % 7))/7 * X;
    cout << max(v1, v2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}