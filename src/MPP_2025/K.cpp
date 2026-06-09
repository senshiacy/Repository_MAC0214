#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

const ll MAXN = 4100;
const ll INF = 1e18;
const ll MOD =  998244353;

ll dp[MAXN][MAXN]; // O segundo argumento sustenta a ideia de ordem

void solve() {
/*
    dp[n][m] -> n chutes sem usar k chutes
    dp[i][j] -> para todo x tal que 1 <= x <= min(i, j) e x != k
    => O(N^3)

    Como otimizar? Note que o único conjunto de chutes 
    pd[i][j] = pd[i][j - 1] + (j != k) ? pd[i-j][j] : 0
*/

    int N, K;
    cin >> N >> K;

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i][j-1]; // Anterior
            dp[i][j] += ((j != K) ? dp[i - j][min(j, i - j)] : 0); // Se não é k, menos que i - j
            if(dp[i][j] > MOD) {
                dp[i][j] -= MOD;
            }
        }
    }

    cout << dp[N][N] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}