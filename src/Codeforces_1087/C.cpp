#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        cout << "? " << 2 * i - 1 << " " << 2 * i << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if(ans == 1) {
            cout << "! " << 2 * i << endl;
            cout.flush();
            return;
        }
    }

    cout << "? 1 3" << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if(ans == 1) {
        cout << "! " << 1 << endl;
        cout.flush();
        return;
    }

    cout << "? 1 4" << endl;
    cout.flush();
    cin >> ans;
    if(ans == 1) {
        cout << "! " << 1 << endl;
        cout.flush();
    }
    else {
        cout << "! " << 2 << endl;
        cout.flush();
    }  
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