#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

void solve() {
    string S;
    cin >> S;
    
    int N;
    cin >> N;

    for(int i = N; i < S.size() - N; i++) {
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