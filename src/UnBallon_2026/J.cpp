#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>
#define int ll

void solve() {
    int N;
    cin >> N;

    int cnt = 0;
    vector<bool> vis(N + 1, false);
    for(int i = 2; i <= N; i++) {
        if(!vis[i]) {
            cnt++;
            for(ll j = i * i; j <= N; j+=i) {
                vis[j] = true;
            }
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