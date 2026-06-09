#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    /**
     * 1- Se existe um número ímpar de 1's não dá
     */
    ll um = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            um++;
        }
    }
    
    if(um % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    /**
     * 2- Se o ciclo possui um número ímpar de uns
     */
    for(int pad = 0; pad < k; pad++) {
        int cnt = 0;
        for(int i = pad; i < n; i+=k) {
            if(s[i] == '1') cnt++;
        }
        if(cnt % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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