#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e8;

void crivo(vector<ll> &primos) {
    // O(N log(log(N)))
    vector<bool> visitados(MAXN, false);
    for(ll i = 2; i < MAXN; i++) {
        if(!visitados[i]) {
            for(ll j = i * i; j < MAXN; j += i) {
                
                visitados[j] = true;
            }
            primos.push_back(i);
        }
    }
}

ll fast_exp(ll a, int n) {
    if(n == 0) {
        return 1;
    }

    ll tmp = fast_exp(a, n/2);
    if(n % 2 == 1) {
        return tmp * tmp * a;
    }
    return tmp * tmp;
}

void solve() {

    vector<ll> primos;
    crivo(primos);

    ll M, N, K;
    cin >> M >> N >> K;

    // M[i] -> <N[j], qtdade>
    // N[j]
    vector<map<int, int>> M_arr(M + 2, map<int, int>());
    vector<ll> N_arr(N + 2);

    for(int i = 1; i <= N; i++) {
        cin >> N_arr[i];
    }
    for(int i = 0; i < K; i++) {
        int m, n, d;
        cin >> m >> n >> d;
        M_arr[m][n] += d;
    }

    int idxp = 0, size = primos.size();
    vector<ll> resp(M + 1);

    for(int i = 1; i <= M; i++) {
        auto [idxn, freq] = *M_arr[i].begin();
        if(N_arr[idxn] > MAXN && freq == 1 && N_arr[(*M_arr[i].begin()).first] == N_arr[(*M_arr[i].rbegin()).first]) {
            resp[i] = N_arr[idxn];
            continue;
        }
        while(idxp < size && (N_arr[idxn] % primos[idxp] != 0)) {
            idxp++;
        }
        resp[i] = primos[idxp];
        for(auto [idxn, freq] : M_arr[i]) {
            N_arr[idxn] = N_arr[idxn] / fast_exp(resp[i], freq);
        }
    }

    for(int i = 1; i <= M; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}