#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

bool is_palindrome(int l, int r, vector<int> &a) {
    while(l < r) {
        if(a[l] != a[r]) {
            return false;
        }
        l++, r--;
    }
    return true;
}

pair<int, int> is_palindrome2(int c, vector<int> &a) {
    int l = c, r = c, n = a.size();
    while(l - 1 >= 0 && r + 1 < n && a[l - 1] == a[r + 1]) {
        l--, r++;
    }
    l = max(l, 0);
    r = min(r, n - 1);
    return make_pair(l, r);
}

int find_mex(int l, int r, vector<int> &a) {
    int n = a.size();
    vector<bool> vis(n + 2, false);
    for(l; l <= r; l++) {
        vis[a[l]] = true;
    }
    int mx = 0;
    while(vis[mx]) {
        mx++;
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    int lz = -1, rz = -1; // Find zeros
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            if(lz == -1) {
                lz = i;
            }
            else {
                rz = i;
            }
        }
    }

    /**
     * There is three cases: 
     * is a palindrome [0..0]
     * [..0_1..] is a palindrome
     * [..0_2..] is a palindrome
     */
    int mex = 0;
    if(is_palindrome(lz, rz, a)) {
        // Maximize the array
        int l = lz, r = rz;
        while(l - 1 >= 0 && r + 1 < 2 * n && a[l - 1] == a[r + 1]) {
            l--;
            r++;
        }
        l = max(l, 0);
        r = min(r, 2 * n - 1);
        vector<bool> vis(n + 2, false);
        for(l; l <= r; l++) {
            vis[a[l]] = true;
        }
        int mx = 0;
        while(vis[mx]) {
            mx++;
        }
        mex = max(mex, mx);
    }

    auto [l1, r1] = is_palindrome2(lz, a);
    auto [l2, r2] = is_palindrome2(rz, a);
    mex = max(mex, find_mex(l1, r1, a));
    mex = max(mex, find_mex(l2, r2, a));

    cout << mex << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        //cout << "test: ";
        //cout << t << endl;
        //cout.flush();
        solve();
    }
}