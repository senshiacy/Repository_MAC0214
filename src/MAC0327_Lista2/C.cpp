/**
 * Mostro um trecho
 * Uma passagem de um livro antigo
 * Pra te provar e mostrar que a vida é linda
 * Dura, sofrida, carente em qualquer continente
 * Mas boa de se viver em qualquer lugar
 */

// AAA

#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n, t;
    cin >> n >> t;
    
    // Two-Pointers
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = -1, tot = 0, cnt = 0, mx = 0;
    while(true) {
        /**
         * 3 1 2 1
         * [3] -> l = r
         * [3, 1] -> l = 0, r = 1
         * [1] -> l = r
         * [1, 2]
         */
        mx = max(mx, cnt);

        if(l >= n || r >= n - 1) {
            break;
        }

        if(tot + a[r + 1] <= t) {
            tot += a[++r];
            cnt++;
        }
        else {
            tot -= a[l++];
            cnt--;
        }

        //cout << l << " " << r << " " << cnt << endl;
    }

    cout << mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}