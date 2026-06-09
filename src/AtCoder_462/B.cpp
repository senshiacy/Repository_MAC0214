#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> A(N + 1, vector<int>());
    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for(int j = 0; j < K; j++) {
            int a;
            cin >> a;
            A[a].push_back(i + 1);
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << A[i].size() << " ";
        for(auto v : A[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}