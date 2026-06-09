#include <iostream>
#include <string>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

void solve() {
    string S;
    cin >> S;

    int cnt = 0, N = S.size();
    for(int i = 0; i < N; i++) {
        if(S[i] == 'C') {
            int val = min(i, N - i - 1) + 1;
            cnt += val;
            //cout << "dbg : " << val << endl;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}