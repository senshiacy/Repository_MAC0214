#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;

void solve() {
    ll N, K;
    cin >> N >> K;

    vector<ll> d(N);
    for(int i = 0; i < N; i ++) {
        cin >> d[i];
    }

    long double r = 1.0;
    for(int val : d) {
        if(val < K) {
            r *= 1.0;
        }
        else {
            r *= ((long double) (K - 1ll)/val);
        }
    }

    cout << fixed << setprecision(16) << 1.0 - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}