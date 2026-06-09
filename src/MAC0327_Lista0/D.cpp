#include <iostream>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    string s;
    cin >> s;

    int mx = 0, n = s.size(), cnt = 0;
    char curr = ' ';

    for(int i = 0; i < n; i++) {
        if(curr == ' ') {
            cnt++;
            curr = s[i];
        }
        else if(curr == s[i]){
            cnt++;
        }
        else {
            mx = max(mx, cnt);
            cnt = 1;
            curr = s[i];
        }
    }

    cout << max(mx, cnt) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1ll;
    //cin >> t;

    while(t--)
        solve();
}