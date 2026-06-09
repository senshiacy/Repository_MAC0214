#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    double b, h, l;
    cin >> b >> h >> l;

    cout << fixed << setprecision(8) << 3*sqrt(3)/2*l*l/(b*h) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}