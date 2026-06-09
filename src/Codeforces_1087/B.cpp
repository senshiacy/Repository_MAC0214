#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        int mn = 0, mx = 0;
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                mx++;
            }
            else if(a[j] < a[i]) {
                mn++;
            }
        }
        cout << max(mx, mn) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}