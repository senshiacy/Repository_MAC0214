#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    vector<vector<int>> D(3, vector<int>(7, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            int x;
            cin >> x;
            D[i][x]++;
        }
    }
    
    cout << setprecision(10) <<
    (double) (
        D[0][4] * D[1][5] * D[2][6] + 
        D[0][4] * D[1][6] * D[2][5] +
        D[0][5] * D[1][4] * D[2][6] +
        D[0][5] * D[1][6] * D[2][4] +
        D[0][6] * D[1][4] * D[2][5] +
        D[0][6] * D[1][5] * D[2][4]
    )/216.0 << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}