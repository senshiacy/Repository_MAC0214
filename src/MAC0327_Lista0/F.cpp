#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int l, n;
    cin >> l >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int earliest = 0;
    for(int i = 0; i < n; i++) {
        earliest = max(earliest, min(a[i], l - a[i]));
    }

    int latest = 0;
    cout << earliest << " " << max(l - a[0], a[n - 1]) << endl;
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