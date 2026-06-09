#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 1e6;

bool verify(map<string, vector<int>> &mp, const string &s) {
    for(int i = 1; i < s.size(); i++) {
        string start = "", end = "";
        for(int j = 0; j < i; j++) {
            start += s[j];
        }
        for(int j = i; j < s.size(); j++) {
            end += s[j];
        }
        //cout << s << " " << start << " " << end << endl;
        if(mp.find(start) != mp.end() && mp.find(end) != mp.end()) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    map<string, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s].push_back(i);
    }

    vector<bool> res(n + 1, false);
    for(auto [st, arr] : mp) {
        bool ans = verify(mp, st);
        for(auto val : arr) {
            res[val] = ans;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i];
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}