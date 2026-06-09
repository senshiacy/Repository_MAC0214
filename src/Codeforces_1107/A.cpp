#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int x, y;
    cin >> x >> y;
    if(x < y or x % y != 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    while(t--)
        solve();
}