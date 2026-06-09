#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;

    vector<int> dp(3, 0);
    for(char c : S) {
        int curr = c - 'a';
        dp[curr] = ((dp[0] + dp[1]) % MOD + dp[2]) % MOD;
        dp[curr] = (dp[curr] + 1) % MOD; // Ele mesmo
    }

    int ans = 0;
    for(auto val : dp) {
        ans = (ans + val) % MOD;
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}