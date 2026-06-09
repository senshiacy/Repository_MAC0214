// Attempt

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>
#define int ll

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    // No moves
    if(a == b) {
        cout << 0 << endl;
        return;
    }

    // 1 move
    ll mn = min(a, b);
    ll mx = max(a, b);
    if(abs(b - a) == 1 || mx/x == mn) {
        cout << 1 << endl;
        return;
    }

    // 2 moves -> Go to zero
    if(a < x and b < x || (mx + 1)/x == mn) {
        cout << 2 << endl;
        return;
    }

    int case1 = abs(b - a);

    int exp = log10(mx/(double) mn)/log10(x);
    int mx2 = mx/pow(x, exp);
    int case2 = (mx2 - mn) + exp;

    int case3 = (int) floor(log10(b)/log10(x)) + (int) floor(log10(a)/log10(x));

    cout << min(case1, min(case2, case3)) << endl;
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