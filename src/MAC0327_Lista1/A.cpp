/// AAAAA

#include <iostream>
#include <deque>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    int q;
    cin >> q;

    deque<int> d;
    bool front = 0; // 0 to leftmost and 1 to right most
    ll rizz = 0, n = 0, sum = 0;
    pll values = {0, 0}; // front, reverse

    while(q--) {
        int s;
        cin >> s;

        if(s == 1) {
            rizz += sum;

            if(front == 0) {
                rizz -= (d.back() * n);
                d.push_front(d.back());
                d.pop_back();
            }
            else {
                rizz -= (d.front() * n);
                d.push_back(d.front());
                d.pop_front();
            }
        }
        if(s == 2) {
            front = !front;
            rizz = (sum * n) - rizz + sum;
        }
        if(s == 3) {
            int k;
            cin >> k;

            // Add k to sum
            sum += k;
            n++;
            rizz += (k * n);

            if(front == 0) {
                d.push_back(k);
            }
            else {
                d.push_front(k);
            }
        }

        cout << rizz << endl;
    }
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