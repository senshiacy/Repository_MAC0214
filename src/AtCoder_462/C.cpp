#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int N;
    cin >> N;

    map<int, int> X;
    map<int, int> Y;
    vector<pii> vals(N);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X[x] = i;
        Y[y] = i;
        vals[i].first = x;
        vals[i].second = y;
    }

    int cnt = 1; // point (1, y)
    int idxc = X[1];
    for(int i = 1; i < N; i++) {
        int idxn = X[i + 1];
        if(vals[idxc].second > vals[idxn].second) {
            cnt++;
            idxc = idxn;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}