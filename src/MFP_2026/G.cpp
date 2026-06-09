#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;

void solve() {
    ll N;
    cin >> N;

    // Passo 1 -> N é potencia de 2?
    ll qtdade = __builtin_popcount(N);
    if(qtdade == 1) {
        cout << "GANHA" << endl;
        return;
    }

    // 3 é ruim
    if(N % 3 == 0) {
        cout << "PERDE" << endl;
        return;
    }


    cout << "GANHA" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}