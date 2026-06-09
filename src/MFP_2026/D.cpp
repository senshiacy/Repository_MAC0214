#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;

void solve() {
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll mx = A[0];
    for(int i = 1; i < N; i++) {
        mx = __gcd(mx, A[i]);
    }

    ll resp = 0;
    for(auto a : A) {
        resp += (a / mx);
    }

    cout << resp << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}