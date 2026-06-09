#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long
#define endl '\n'
#define ll long long
#define pll pair<ll, ll>

const double INF = 1e10;
const double MAXN = 1e9;
//const double eps = 1e-7;
int n;
long double w;
vector<long double> p, t;

bool valido(long double Ti) {
    long double trigo = 0;
    for(int i = 0; i < n; i++) {
        if (trigo >= w) return true; 
        if(Ti < 2 * t[i]) continue;
        trigo += (p[i] * (Ti - 2 * t[i]));
    }

    if(trigo < w) {
        return false;
    }
    else {
        return true;
    }
}

void solve() {

    cin >> n >> w;
    p.resize(n);
    t.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> t[i];
    }

    long double l = 0, r = INF;
    long double ans = 0;

    while(r - l >= 1e-6) {
        long double Ti = l + (r - l)/2.0;
        if(valido(Ti)) {
            ans = Ti;
            r = Ti;
        }
        else {
            l = Ti;
        }
    }

    cout << setprecision(16) << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}