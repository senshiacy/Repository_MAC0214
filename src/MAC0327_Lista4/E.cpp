#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 2e6;
ll const INF = 1e18;
ll const MOD =  1000000007;

void crivo(vector<int> &primes) {
    vector<bool> is_composite(MAXN, false);
    for(ll i = 2; i < MAXN; i++) {
        if(!is_composite[i]) {
            primes[i] = 1;
            for(ll j = 2 * i; j < MAXN; j += i) {
                is_composite[j] = true;
                primes[j] = 0;
            }
        }
    }
}

void solve(vector<ll> &acc) {
    int i, j;
    cin >> i >> j;
    cout << acc[j] - acc[i - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> primes(MAXN);
    crivo(primes);

    vector<ll> acc(MAXN, 0);
    for(int i = 2; i < MAXN; i++) {
        acc[i] = acc[i -1] + primes[i];
    }

    ll T;
    cin >> T;

    while(T--)
        solve(acc);
}