#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll const MAXN = 2e6;
ll const INF = 1e18;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<char> st;
    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            st.push(s[i]);
        }
        else if(st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }

    if(st.empty()) {
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

    ll t = 1ll;
    cin >> t;

    while(t--)
        solve();
}