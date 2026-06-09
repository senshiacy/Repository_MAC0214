/**
 * Quem me dera ao menos uma vez
 * Como a mais bela tribo
 * Dos mais belos índios
 * Não ser atacado por ser inocente
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 2e5 + 10;

array<ll, MAXN> a;
array<ll, MAXN> acc;

bool query(int l, int r) {
    cout << "? " << r - l + 1 << " ";
    for(int i = l; i <= r; i++) {
        cout << i << " ";
    }
    cout << endl;
    cout.flush();

    int size;
    cin >> size;
    //cout.flush();
    //cout << size << " AAAAAA " << endl;
    if(size == acc[r] - acc[l] + a[l]) {
        return false;
    }
    return true;
}

void busca(int n) {
    int l = 1, r = n;

    while(l < r) { // A resposta é quando os dois se sobreporem
        int mid = (l + r)/2;
        if(query(l, mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    acc[0] = a[0];
    for(int i = 2; i <= n; i++) {
        acc[i] = acc[i-1] + a[i];
    }

    busca(n);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}