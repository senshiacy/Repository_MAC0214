#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());

    vector<int> acc(n, 0);
    acc[0] = v[0];
    for(int i = 1; i < n; i++) {
        acc[i] = v[i] + acc[i - 1];
    }

    while(q--) {
        int c;
        cin >> c;

        // Eu quero o menor número de doces para comer que seja maior ou igual a c
        auto res = lower_bound(acc.begin(), acc.end(), c);
        if(res == acc.end()) {
            cout << -1 << endl;
        }
        else {
            cout << res - acc.begin() + 1 << endl;
        }
    }
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