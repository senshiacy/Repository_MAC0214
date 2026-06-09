#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    /**
     * N
     * A1 ... AN
     */

    int N;
    cin >> N;

    map<int, int> freq;

    for(int i = 0; i < N; i++) {
        int curr;
        cin >> curr;

        freq[curr]++;
    }

    int res = 0;
    for(auto [val, f] : freq) {
        res += (f / 2);
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}