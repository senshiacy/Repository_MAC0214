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
    set<ll> A;
    vector<ll> vA(N);
    for(ll i = 0; i < N; i++) {
        cin >> vA[i];
        A.insert(vA[i]);
    }

    sort(vA.begin(), vA.end());

    if(N == 1 && vA[0] == 1) {
        cout << '*' << endl;
        return;
    }
    if(N == 1) {
        cout << vA[N-1] << " " << 1 << endl;
        return;
    }

    // Existe algum A[i] que não divide A[n] -> A[n] != d
    for(auto a : A) {
        if(vA[N-1] % a != 0) {
            cout << vA[1] * vA[N-1] << " " << vA[1] * vA[N-1] << endl;
            return;
        }
    }
    // Portanto A[N] = X
    for(auto a : A) {
        ll x = vA[N - 1]/a;
        if(A.find(x) == A.end()) {
            cout << vA[N-1] << " " << x << endl;
            return;
        }
    }
    ll x = (ll) round(sqrtl(vA[N-1]));
    if(x * x == vA[N-1] && A.find(x) == A.end()) {
        cout << vA[N-1] << " " << x << endl;
        return;
    }

    cout << vA[1] * vA[N-1] << " " << vA[1] * vA[N-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}