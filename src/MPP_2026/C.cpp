#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const INF = 1e18;

void solve() {
    ll N, M;
    cin >> N >> M;
    cout << (int) floor(N * 8/M) << endl;
}


signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   solve();
}