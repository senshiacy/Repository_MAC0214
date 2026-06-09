#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int n;
    cin >> n;

    vector<ll> by6, only2, only3, neither;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x % 2 == 0 and x % 3 == 0) {
            by6.push_back(x);
        }
        else if(x % 2 == 0 and x % 3 != 0) {
            only2.push_back(x);
        }
        else if(x % 2 == 1 and x % 3 == 0) {
            only3.push_back(x);
        }
        else {
            neither.push_back(x);
        }
    }

    for(auto val : by6) {
        cout << val << " ";
    }
    for(auto val : only2) {
        cout << val << " ";
    }
    for(auto val : neither) {
        cout << val << " ";
    }
    for(auto val : only3) {
        cout << val << " ";
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