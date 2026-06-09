#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>

bool is_valid(int k, int kdx, int K) {
    if(k + kdx < 0) {
        return false;
    }
    if(k + kdx >= K) {
        return false;
    }
    return true;
}

void solve() {
    int H, W;
    cin >> H >> W;

    array<pair<int, int>, 4> borders = 
    {
        make_pair(0, -1), 
        make_pair(0, 1),
        make_pair(-1, 0),
        make_pair(1, 0)
    };

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int cnt = 0;
            for(auto [idx, jdx] : borders) {
                if(is_valid(i, idx, H) && is_valid(j, jdx, W)) {
                    cnt++;
                }
            }
            cout << cnt << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}