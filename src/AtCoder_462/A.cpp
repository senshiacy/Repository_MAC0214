#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++) {
        if(S[i] - 'a' >= 0 and S[i] - 'z' <= 0) {
            continue;
        }
        cout << S[i];
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}