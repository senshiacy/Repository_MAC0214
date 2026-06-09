/**
 * And I miss you
 * (Like the deserts miss the rain)
 * And I miss you, oh
 * (Like the deserts miss the rain)
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

ll const MOD = 1e9 + 7;
ll const MAXN = 1e5 + 10;

ll dp[110][MAXN];

void solve() {
    /**
     * The mainly idea is optimize the space of DP
     * Of course, we couldn't use dp[100][1e9], where dp[i][j] is the maximum value with [0, i] objects and the i-th has weight j
     * However, looking through another perspective, we can use dp[100][100 * 1e3]
     * Where dp[i][j] is the minimum weight with [0, i] objects that sum value j
     */

    ll N, W;
    cin >> N >> W;
    vector<int> w(N + 1);
    vector<int> v(N + 1);
    ll smx = 0;
    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        smx += v[i];
    }

    /**
     * dp(int i, int j) = {
     *      temos de 0 a i objetos (0 a 100)
     *      o valor j (0 a 10ˆ5)
     * }
     */

    /**
     * In here we look if is lighter dp[i-1][j - v[i]] + w[i] -> If we take this object
     * Or, its lighter 
     */

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= smx; j++) {
            if(i == 0 && j == 0) {
                // No objects, no weight
                dp[i][j] = 0;
                continue;
            }
            if(i == 0) {
                // No objects, no value
                dp[i][j] = MOD;
                continue;
            }
            // Can we add 
            if(j - v[i] < 0) {
                dp[i][j] = dp[i - 1][j]; // The same value, we didn't try take another item
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    } 

    ll ans = 0;
    for(int i = smx; i >= 0; i--) {
        if(dp[N][i] <= W) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}