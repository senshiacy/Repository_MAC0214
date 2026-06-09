/**
 * Vamos fugir
 * Deste lugar, baby
 * Vamos fugir
 * Tô cansado de esperar
 * Que você me carregue
 */

#include <iostream>
#include <vector>
#include <array>
#define int long long

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

int n, k;
vector<int> x;

bool verify(int mid) {
    int p = 0, mx = 0, cnt = 0;

    for(auto val : x) {
        if(val > mid) {
            return false;
        } 
        else if(p + val <= mid) { // val <= mid
            p += val;
            cnt++;
        }
        else {
            mx++;
            cnt = 1;
            p = val;
        }
    }

    if(p > 1) {
        mx++;
    }

    if(mx <= k) {
        return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    x.resize(n); int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        mx += x[i];
    }

    int l = 0, r = mx;
    while(l < r) {
        int mid = (l + r)/2;
        if(verify(mid)) {
            //cout << mid << endl;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}