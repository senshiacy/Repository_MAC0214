#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    int D, M;
    cin >> D >> M;

    if(D <= 12 and D != M) {
        cout << "DATA INCERTA" << endl;
    }
    else {
        cout << "DATA SEGURA" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}