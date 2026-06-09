/**
 * Shout, shout, let it all out
 * These are the things I can do without
 * Come on
 * I'm talking to you, come on
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

ll const MAXN = 1e6 + 100;
ll const MOD = 1e9 + 7;

ll dp[MAXN][10];

void processa() {
    // Base
    for(int i = 0; i < 6; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i < MAXN; i++) {
        for(int j = 0; j < 6; j++) {
            // 0 -> 0, 2, 5
            if(j == 0) {
                dp[i][j] = (((dp[i-1][0] + dp[i-1][2])%MOD) + dp[i-1][5])%MOD;
            }
            // 1 -> 1, 2, 3, 4, 5
            else if(j == 1) {
                dp[i][j] = ((((dp[i-1][1] + dp[i-1][2])%MOD + dp[i-1][3])%MOD + dp[i-1][4])%MOD + dp[i-1][5])%MOD;
            }
            // 2 -> 0, 2, 5
            else if(j == 2) {
                dp[i][j] = ((dp[i-1][0] + dp[i-1][2]) % MOD + dp[i-1][5])%MOD;
            }
            // 3 -> 1, 2, 3, 4, 5
            else if(j == 3) {
                dp[i][j] = ((((dp[i-1][1] + dp[i-1][2])%MOD + dp[i-1][3])%MOD + dp[i-1][4])%MOD + dp[i-1][5])%MOD;
            }
            // 4 -> 1, 2, 3, 4, 5
            else if(j == 4) {
                dp[i][j] = ((((dp[i-1][1] + dp[i-1][2])%MOD + dp[i-1][3])%MOD + dp[i-1][4])%MOD + dp[i-1][5])%MOD;
            }
            // 5 -> 1, 2, 3, 4, 5
            else {
                dp[i][j] = ((((dp[i-1][1] + dp[i-1][2])%MOD + dp[i-1][3])%MOD + dp[i-1][4])%MOD + dp[i-1][5])%MOD;
            }
        }
    }
}

void solve(int n) {
    cout << (dp[n][2] + dp[n][5]) % MOD << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    processa();

    ll t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
}