#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e9 + 10;

void solve() {
    map<ll, ll> sum;
    int i = 1;
    while(i * i < MAXN) {
        sum[i * i] = 1;
        i++;
    }
    sum[i * i] = 1;

    int cnt = 0;
    for(auto [idx, freq] : sum) {
        cnt += freq;
        sum[idx] = cnt;
    }

    ll Q;
    cin >> Q;
    while(Q--) {
        ll L, R;
        cin >> L >> R;

        ll mn = sum.lower_bound(L)->second;
        ll mx = sum.lower_bound(R)->second;
        if(sum.find(R) != sum.end()) {
            cout << mx - mn + 1 << endl;
        }
        else {
            cout << mx - mn << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}