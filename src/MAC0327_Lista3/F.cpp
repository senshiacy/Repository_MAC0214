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

ll const MAXN = 1010;
ll const MOD = 1e9 + 7;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> ribbon(n + 1, 0);

    if(a <= n)
        ribbon[a] = 1;
    if(b <= n)
        ribbon[b] = 1;
    if(c <= n)
        ribbon[c] = 1;

    for(int i = 0; i <= n; i++) {
        if(i - a >= 0 && ribbon[i - a] > 0) {
            ribbon[i] = max(ribbon[i], ribbon[i - a] + ribbon[a]);
        }
        if(i - b >= 0 && ribbon[i - b] > 0) {
            ribbon[i] = max(ribbon[i], ribbon[i - b] + ribbon[b]);
        }
        if(i - c >= 0 && ribbon[i - c] > 0) {
            ribbon[i] = max(ribbon[i], ribbon[i - c] + ribbon[c]);
        }
        //cout << i << " " << ribbon[i] << endl;
    }

    cout << ribbon[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}