#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const INF = 1e18;

void solve() {
    ll N;
    cin >> N;
    vector<ll> T(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<ll> acc(N);
    acc[0] = T[0];
    for(int i = 1; i < N; i++) {
        if(acc[i - 1] + T[i] > 120 and acc[i - 1] + T[i] < 300) {
            acc[i] = acc[i - 1] + T[i] + 180;
        }
        else if(acc[i - 1] + T[i] > 720 and acc[i - 1] + T[i] < 900) {
            acc[i] = acc[i - 1] + T[i] + 180;
        }
        else {
            acc[i] = acc[i-1] + T[i];
        }
    }

    cout << acc[N-1] << endl;
}


signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   solve();
}