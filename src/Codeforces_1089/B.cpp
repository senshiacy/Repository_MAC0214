#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    /**
     * Visitando a cadeira i 
     * Se pi = i, então, dá para usar
     * Se pi = j
     *      Se j >= k:
     *          - Dá para sentar
     *      Se j < k:
     *          - Pula
     */

     /**
      * 1:
      *     3 > 1, dá para pegar
      * 2:
      *     2 == 2, dá para pegar
      * 3:
      *     Já foi visitado
      */

      /**
       * 1:
       *    4 > 1, dá para pegar 
       * 2: 
       *    3 > 2, dá para pegar
       * 3:
       *    Já foi visitado
       */

        /**
         * 1: 
         *      4 > 1, dá para pegar
         * 
         */

         int cnt = 0;
         for(int i = 1; i <= n; i++) {
            if(p[i] <= i) {
                cnt++;
            }
         }

         cout << cnt << endl;
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