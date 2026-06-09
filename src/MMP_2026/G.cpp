#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    int N, G;
    cin >> N >> G;

    if(G > 1)
        cout << 2 * (G - 1) + (N - (G - 1) + 1) << endl;
    else
        cout << N + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}