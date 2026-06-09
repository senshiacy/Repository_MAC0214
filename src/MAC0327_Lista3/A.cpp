#include <iostream>
#include <array>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6 + 10;
ll const MOD = 1e9 + 7;

void solve() {
    //    [0 1 2 3 4 5 6 7 8 9]
    // [2][-1]
    // [3]
    // [5]

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    array<ll, MAXN> ans;
    fill(ans.begin(), ans.begin() + x + 1, 0);
    for(int i = 0; i <= x; i++) {
        for(auto v : a) {
            if(i == v) {
                ans[i] = (ans[i] + 1) % MOD;
            }
            if(i - v >= 0) {
                ans[i] = (ans[i] + ans[i - v]) % MOD;
            }
        }
    }

    cout << ans[x] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}