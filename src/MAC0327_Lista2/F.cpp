#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 200010;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> arr(MAXN, 0);
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
    }
    for(int i = 1; i < MAXN; i++) {
        arr[i] += arr[i-1];
    }

    vector<ll> acc(MAXN, 0);
    for(int i = 0; i < MAXN; i++) {
        if(arr[i] >= k) {
            acc[i]++;
        }
    }
    for(int i = 1; i < MAXN; i++) {
        acc[i] += acc[i - 1];
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << acc[b] - acc[a - 1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}