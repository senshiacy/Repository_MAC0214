#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e9 + 10;

void solve() {
    int N;
    cin >> N;

    vector<int> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }
    vector<pii> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(G.rbegin(), G.rend());
    sort(A.begin(), A.end());

    vector<int> ans(N);
    ans[A[0].second] = G[0];
    int curr = A[0].first + G[0];
    for(int i = 1; i < N; i++){
        if(curr != G[i] + A[i].first) {
            cout << "NAO" << endl;
            return;
        }
        curr = G[i] + A[i].first;
        ans[A[i].second] = G[i];
    }

    cout << "SIM" << endl;
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}