#include <iostream>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

// Mandamento do maratonista : usarás #define int long long enquanto puder

void solve() {
    ll n;
    scanf("%lld", &n);

    while(n != 1) {
        printf("%lld ", n);
        if((n & 1) == 0) {
            n = n >> 1;
        }
        else {
            n = 3 * n + 1;
        }
    }
    printf("%lld\n", n); // Que certamente é 1
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1ll;
    //cin >> t;

    while(t--)
        solve();
}