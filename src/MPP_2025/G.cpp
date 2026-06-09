#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    char B1, B2, T, E1, E2;
    cin >> B1 >> B2 >> T >> E1 >> E2;
    if(E1 == 'S' && E2 == 'P') {
        cout << "S" << endl;
    }
    else if(E1 == '?' && E2 == 'P' || E1 == 'S' && E2 == '?') {
        cout << "T" << endl;
    }
    else {
        cout << "N" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}