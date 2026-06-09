#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int W, K;
    cin >> W >> K;
    // Em K, K - W
    // (K - W + X) = 2X
    // K - W + X = 2X
    // K - W
    cout << 2 * K - W  << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}