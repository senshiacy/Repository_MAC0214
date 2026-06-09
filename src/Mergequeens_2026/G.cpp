#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {

    int N;
    cin >> N;
    string s;
    cin >> s;

    int l = 0, r = 0, mx = 1;
    char curr = s[0];

    while(r < N) {
        while(r < N && s[l] == s[r]) {
            r++;
        }
        if(mx < r - l) {
            mx = r - l;
            curr = s[l];
        }
        l = r;
    }

    cout << mx << endl;
    cout << curr << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}