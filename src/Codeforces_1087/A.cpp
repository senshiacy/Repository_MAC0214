#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define endl '\n'
#define int long long

void solve() {
    ll n, c, k;
    cin >> n >> c >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(c < a[i]) {
            break;
        }
        
        int range = c - a[i];
        if(range <= k) {
            c *= 2;
            k -= range;
        }
        else {
            c += (a[i] + k);
            k = 0;
        }
    }

    cout << c << endl;
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