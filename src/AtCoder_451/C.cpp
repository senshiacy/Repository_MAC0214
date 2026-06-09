#include <iostream>
#include <set>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>

void solve() {
    int Q;
    cin >> Q;

    multiset<ll> ms;
    while(Q--) {
        int op;
        ll h;
        cin >> op >> h;

        if(op == 1) {
            ms.insert(h);
        }
        else {
            if(!ms.empty() && *ms.begin() <= h) {
                ms.erase(ms.begin(), ms.upper_bound(h));
            }
        }

        //for(auto v : ms) {
        //    cout << v << " ";
        //}
        //cout << endl;
        //cout << "Tamanho: " << ms.size() << endl;
        cout << ms.size() << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}