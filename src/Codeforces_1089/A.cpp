#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    /**
     * 1 mod 2
     * 
     * 2 mod 3, 3 mod 1
     * 
     * 5 mod 4 -> 1
     * 4 mod 3 -> 1
     * 3 mod 2
     * 2 mod 1
     */

     for(int i = n; i > 0; i--) {
        cout << i << " ";
     }
     cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}