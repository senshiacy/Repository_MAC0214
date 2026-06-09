/**
 * Há uma luz no túnel
 * Dos desesperados
 * Há um cais de porto
 * Pra quem precisa chegar
 * Eu 'to na Lanterna dos Afogados
 * Eu 'to te esperando
 * Vê se não vai demorar
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 2e5 + 10;

int n;
array<pll, MAXN> amigos;

bool verify(int mid) {

    int v = -1;
    for(int i = 0; i < n; i++) { // Find the poorest person
        auto [a, b] = amigos[i];
        if(
            0 >= mid - 1 - amigos[i].first &&
            0 <= amigos[i].second
        ) {
            v = i;
            break;
        }
    }

    if(v == -1) {
        return false;
    }

    int cnt = 1;
    for(int i = v + 1; i < n; i++) {
        if(
            cnt >= mid - 1 - amigos[i].first &&
            cnt <= amigos[i].second
        ) {
            cnt++;
            v = i;
        }
    }

    return cnt >= mid;
}

void busca() {
    int l = 0, r = n, ans = -1;

    while(l <= r) {
        int mid = (l + r)/2;
        if(verify(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

void solve() {
    cin >> n;
    
    /**
     * 1 2 -> 1
     * 2 1 -> 2
     * 1 1 -> 3
     * 
     * O lowerbound é dado por min(i - 1, l) + min(n - i, u)
     */

    for(int i = 0; i < n; i++) {
        cin >> amigos[i].first >> amigos[i].second;
    }

    busca();
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