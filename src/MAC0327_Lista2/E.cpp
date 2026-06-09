#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>
#define int ll

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    // Sweep-line + Preffix Sum
    // 0 -> abre, 1 -> fecha

    vector<array<int, 3>> ops(m + 1);
    for(int i = 1; i < m + 1; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    //return;

    // Soma acumulada sobre as operações
    vector<int> acc_ops(m + 1, 0);
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        acc_ops[x]++;
        if(y + 1 < m + 1)
            acc_ops[y + 1]--;
    }
    for(int i = 2; i < m + 1; i++) {
        acc_ops[i] += acc_ops[i - 1];
    }
    //return;

    /*
    for(int i = 1; i < m + 1; i++) {
        cout << acc_ops[i] << " ";
    }
    cout << endl;
    */

    vector<ll> acc(n + 1, 0);
    for(int i = 1; i < m + 1; i++) {
        auto [l, r, d] = ops[i];
        acc[l] = acc[l] + d * acc_ops[i];
        if(r + 1 < n + 1)
            acc[r + 1] = acc[r + 1] - d * acc_ops[i];
    }
    for(int i = 2; i < n + 1; i++) {
        acc[i] += acc[i - 1];
    }

    //for(int i = 1; i < n + 1; i++) {
    //    cout << acc[i] << " ";
    //}
    //cout << endl;

    for(int i = 1; i < n + 1; i++) {
        cout << a[i] + acc[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}