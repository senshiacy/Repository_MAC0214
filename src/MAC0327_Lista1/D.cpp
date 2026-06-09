#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int q; cin >> q;
    while(q--) {
        int m; cin >> m;
        auto it = upper_bound(x.begin(), x.end(), m);
        cout << it - x.begin() << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}