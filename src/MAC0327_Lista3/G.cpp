/**
 * Pois aquele garoto que ia mudar o mundo
 * Mudar o mundo
 * Agora assiste a tudo em cima do muro
 * Em cima do muro
 */

#include <iostream>
#include <array>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>
#define int long long

ll const MAXN = 1010;
ll const MOD = 1e9 + 7;

ll dp[10000];
ll dp_d[100000];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    for(int i = 0; i <= n; i++) {
        dp[i] = 0;
        dp_d[i] = 0;
    }

    dp[0] = 1;
    dp_d[0] = 1;

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i + j] = (dp[i + j] + dp[i]) % MOD;

            // At least d
            if(j < d) {
                dp_d[i + j] = (dp_d[i + j] + dp_d[i]) % MOD;
            }
        }
    }

    cout << ((dp[n] - dp_d[n] + MOD) % MOD) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}