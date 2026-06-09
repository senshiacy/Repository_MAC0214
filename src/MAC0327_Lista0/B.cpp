#include <iostream>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int w;
    cin >> w;

    if(((w & 1) == 1) || w == 2) {
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

    ll t = 1ll;
    //cin >> t;

    while(t--)
        solve();
}