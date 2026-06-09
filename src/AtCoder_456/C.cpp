#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;

    vector<pair<char, int>> freq;
    int l = 0, r = 0;
    while(r < S.size()) {
        while(r < S.size() and S[l] == S[r]) {
            r++;
        }
        freq.push_back(make_pair(S[l], r - l));
        l = r;
    }

    int n = freq.size();
    vector<int> acc(n, 0);
    vector<int> contains(n, 0);
    acc[0] = freq[0].second; // Always exists, bc S.size() > 0
    contains[0] = 1;
    for(int i = 1; i < n; i++) {
        /*
        if(freq[i - 1].second > 1) { // If the before
            ll one = (2 * )
        }
        else {
            ll one = ((2 * acc[i - 1]) % MOD + 1) % MOD;
            acc[i] = one;
            one_acc[i] = one;
            if(freq[i].second > 1) {
                ll tot = (acc[i - 1] * (freq[i].second - 1)) % MOD;
                acc[i] = (((one * freq[i].second) % MOD) - tot) % MOD;
            }
        }
        */
        acc[i] = acc[i - 1];
        //acc[i] = (acc[i] + freq[i].second) % MOD;
        if(freq[i].second == 1) { // ba...
            acc[i] = (acc[i] + contains[i - 1]) % MOD;
            contains[i] = (contains[i - 1] + 1) % MOD;
        }
        else { //a1a2
            acc[i] = (acc[i] + contains[i - 1]) % MOD;
            contains[i] = 1;
        }
        acc[i] = (acc[i] + (freq[i].second)) % MOD;
    }
    /*
    for(int i = 0; i < n; i++) {
        cout << freq[i].second << " : " << acc[i] << " | ";
    }
    cout << endl;
    */
    //cout << acc[n - 1] << endl;
    

    /**
     *     vector<int> acc(S.size(), 0);
    acc[0] = 1; // Always!
    for(int i = 1; i < S.size(); i++) {
        if(S[i] != S[i - 1]) {
            acc[i]
        }
    }
    */
    cout << acc[n - 1] << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}