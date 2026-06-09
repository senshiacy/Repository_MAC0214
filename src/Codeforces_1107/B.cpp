#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    unordered_map<char, int> freq;
    int cnt = 0;
    
    string s;
    cin >> s;
    for(auto c : s) {
        if(freq[c] == 0) {
            freq[c]++;
            cnt++;
        }
    }
    if(cnt == 1) {
        cout << 10 << endl;
    }
    else {
        int n = s.size();
        cout << 1;
        for(int i = 0; i < n - 1; i++) {
            cout << 0;
        }
        cout << 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    while(t--)
        solve();
}