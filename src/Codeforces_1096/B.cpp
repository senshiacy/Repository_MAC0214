#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int l = 0, r = 0;
    for(auto c : s) {
        if(c == '(') {
            l++;
        }
        else {
            r++;
        }
    }

    if(l == r) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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