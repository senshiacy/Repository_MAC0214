#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6 + 10;
ll const MODN = 1e9 + 7;

void solve() {
    pair<ll, ll> prod; // <pair[0] * X + prod[1]>
    prod.first = 1;
    prod.second = 0;

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        char c; cin >> c;
        ll val; cin >> val;

        if(c == '+') {
            prod.second = (prod.second + val) % MODN;
        }
        else if(c == '*') {
            prod.first = (prod.first * val) % MODN;
            prod.second = (prod.second * val) % MODN;
        }
        else {
            cout << ((val * prod.first) % MODN + prod.second) % MODN << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}