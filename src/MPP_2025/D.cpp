#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll par<ll, ll>
#define endl '\n'
#define pii pair<int, int>

int N, M, P, S;

void solve() {
    cin >> N >> M >> P >> S; // ingredientes, pares que não combinam, paes, salsicha

    /**
     * Using SOS DP
     * There are N <= 20 ingredients
     * So, each bit can represent if an ingredient is in the counting
     */

     // What ingredients can't be together
     vector<ll> adj(N, 0); // N ingredients
     for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u] |= (1ll << v);
        adj[v] |= (1ll << u);
    }

    // Ingredients x P/S
    int ING = N - P - S;
    vector<int> bad_others(P + S, 0); // What doesn't combines with (P, O) or (S, O);
    for(int i = 0; i < P + S; i++) {
        for(int j = 0; j < ING; j++) {
            if(adj[i] & (1ll << (P + S + j))) {
                bad_others[i] |= (1 << j); // These ingredient don't combines with this bread or sausage
            }
        }
    }

    // Ingredient x Ingredient
    vector<int> bad_internal(ING, 0);
    for(int i = 0; i < ING; i++) {
            for(int j = 0; j < ING; j++) {
                if(adj[P + S + i] & (1ll << (P + S + j))) {
                    bad_internal[i] |= (1 << j);
            }
        }
    }

    // Valid subset of Others -> Which subsets is valid?
    int max_mask = 1 << ING;
    vector<ll> F(max_mask, 0); // All combinations : 2 ** ING
    for(int mask = 0; mask < max_mask; mask++) {
        bool ok = true;
        for(int i = 0; i < ING; i++) {
            // The ingredient i is in subset
            if((mask & (1 << i)) && (mask & bad_internal[i])) { // There is some ingredient in this subset that don't combines with i?
                ok = false;
                break;
            }
        }
        if(ok) {
            F[mask] = 1;
        }
    }

    // SOS DP
    // F[mask] will mark
    for(int i = 0; i < ING; i++) {
        for(int mask = 0; mask < max_mask; mask++) {
            if(mask & (1 << i)) { // i-th ingredient is in subset
                // F[mask] = quantas combinações válidas com os ingredientes do subset?
                // A soma das variações dos subconjuntos
                F[mask] += F[mask ^ (1 << i)]; // Os que não possuem
            }
        }
    }

    ll tot_hot = 0;
    for(int p = 0; p < P; p++) {
        for(int s = P; s < P + S; s++) {
            if(adj[p] & (1ll << s)) {
                continue; // combinacao invalida de pao e salsicha
            }

            int bad_mask = bad_others[p] | bad_others[s]; // Todos os ingredientes que não combinam com o pão e com a salsicha
            int allowed_mask = (max_mask - 1) ^ bad_mask; // Todos os ingredientes que combinam com o pão e a salsicha
            tot_hot += F[allowed_mask];
        }
    }

    cout << tot_hot << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}