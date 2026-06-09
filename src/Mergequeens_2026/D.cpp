#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int A, B;
    cin >> A >> B;
    if(max(A, B) % 2 == 0) {
        cout << max(A, B) << endl;
        return;
    }
    else if(min(A, B) % 2 == 0) {
        cout << min(A, B) << endl;
        return;
    }
    else {
        cout << -1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}