/*
* O teu futuro é duvidoso
* Eu vejo grana, eu vejo dor
* No paraíso perigoso
* Que a palma da tua mão mostrou
*/

#include <iostream>
#include <array>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1010;
ll const MOD = 1e9 + 7;
array<array<char, MAXN>, MAXN> grid;
array<array<ll, MAXN>, MAXN> ans;

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '.')
        ans[0][0] = 1;
    else
        ans[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(grid[i][j] == '*') {
                ans[i][j] = 0;
            }
            else if(i == 0) {
                ans[i][j] = ans[i][j - 1];
            }
            else if(j == 0) {
                ans[i][j] = ans[i - 1][j];
            }
            else {
                ans[i][j] = (ans[i - 1][j] + ans[i][j - 1]) % MOD;
            }
        }
    }

    cout << ans[n - 1][n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}