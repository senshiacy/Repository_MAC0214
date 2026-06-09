#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> F[i];
    }

    map<int, int> freq;
    for(int i = 1; i <= N; i++) {
        int f = F[i];
        freq[f]++;
    }

    if(freq.size() == N) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    if(freq.size() == M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    //cin >> t;

    while(t--)
        solve();
}