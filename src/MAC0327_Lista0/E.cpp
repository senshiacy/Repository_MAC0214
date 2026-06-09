#include <iostream>
#include <string>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, s[i] - 'a');
    }
    cout << mx + 1 << endl;
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