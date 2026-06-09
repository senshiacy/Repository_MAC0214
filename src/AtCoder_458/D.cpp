#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

multiset<int> mn;
multiset<int> mx;
int cnt = 1;

void solve() {
    vector<int> vals(2);
    cin >> vals[0] >> vals[1];
    sort(vals.begin(), vals.end());

    int A = vals[0], B = vals[1];
    // In here mn.size() is cnt/2 + 1
    // And mx.size() is cnt/2

    int mntop = *mn.rbegin();
    if(A <= mntop) {
        mn.insert(A);
    }
    else {
        mx.insert(A);
        int mxtop = *mx.begin();
        mx.erase(mx.find(mxtop));
        mn.insert(mxtop);
    }

    // In this line, mn.size() is (cnt + 1)/2 + 1
    mntop = *mn.rbegin();
    if(B < mntop) { // We have to transfer
        mn.insert(B);
        mn.erase(mn.find(mntop));
        mx.insert(mntop);
    }
    else {
        mx.insert(B);
    }

    cout << *mn.rbegin() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, Q;
    cin >> X >> Q;

    mn.insert(X);
    while(Q--)
        solve();
}