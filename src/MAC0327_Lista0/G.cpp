#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define int long long

void solve() {
    int L, G;
    cin >> L >> G;

    int res = -1;

    for(int i = 0; i < G; i++) {
        int p, d;
        cin >> p >> d;
        if(d == 0) {
            res = max(res, p);
        }
        else {
            res = max(res, L - p);
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}