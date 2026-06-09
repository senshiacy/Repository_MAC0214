#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 2e6;
ll const INF = 1e18;
ll const MOD =  1000000007;

void solve() {
    // Identidade de Bezout ax + by = mdc(a, b)
    // x é alcançável <-> mdc(a1, ..., an) | x
    ll n, x;
    cin >> n >> x;
    
    ll g;
    cin >> g;
    for(int i = 1; i < n; i++) {
        ll a;
        cin >> a;
        g = __gcd(g, a);
    }

    if(x % g == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}