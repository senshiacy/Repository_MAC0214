#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>
#define int ll

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> R(M + 1);
    for(int i = 0; i < N; i++) {
        int r;
        cin >> r;
        R[r]++;
    }

    vector<int> acc(M + 1, 0);
    acc[M] = R[M] * M;
    for(int i = M-1; i >= 0; i--) {
        acc[i] = acc[i+1] + i * R[i];
    }

    for(int i = 1; i <= M; i++) {
        cout << acc[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}