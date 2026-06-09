#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

const int MAXN = 1e6 + 100;

vector<int> primes[MAXN]; // Primos que dividem i
vector<int> cnt(MAXN, 0); // Quantos primos tem resposta igual a i
vector<int> r(MAXN, 0);

void crivo(){
	vector<bool> is_composite(MAXN, false);
    int num_primes = 0;

	for(int i = 2; i < MAXN; i++){
		if(not is_composite[i]){
            num_primes++;
            for(int j = i; j < MAXN; j += i) {
                is_composite[j] = true;
                primes[j].push_back(i);
            }
		}
	}
    cnt[0] = num_primes;
}

void inc(int p, int k) {
    cnt[r[p]]--;
    r[p] += k;
    cnt[r[p]]++;
}

void solve() {
    int N, D;
    cin >> N;

    crivo();

    int best = 0;
    vector<bool> light(MAXN, false);

    for(int i = 0; i < N; i++) {
        cin >> D;
        light[D] = !light[D];

        for(auto p : primes[D]) {
            if(light[D]) {
                inc(p, 1);
                best = max(best, r[p]);
            }
            else {
                inc(p, -1);
            }
        }

        if(cnt[best] == 0) {
            best--;
        }
        cout << best << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}