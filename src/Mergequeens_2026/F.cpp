#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Qual é o Tier Máximo?
    vector<bool> vis(MAXN, false);
    for(int i = 0; i < N; i++) {
        vis[A[i]] = true;
    }
    int idx = 0;
    while(vis[idx + 1] == true) {
        idx++;
    }

    if(idx == 0) { // Não tem nem 1
        cout << -1 << endl;
        return;
    }

    // idx corresponde ao maior tier possível
    // E é o tamanho da sliding window que a gente está buscando
    vector<ll> freq(MAXN, 0);
    int cnt = 0, mn = N;
    int l = 0, r = -1;

    while(l < N) {
        while(l < N and cnt < idx) {
            if(A[l] <= idx and freq[A[l]] == 0) {
                cnt++;
            }
            freq[A[l]]++;
            l++;
        }
        while(r + 1 < N and cnt >= idx) {
            if(A[r + 1] <= idx and freq[A[r + 1]] - 1 == 0) {
                cnt--;
            }
            freq[A[r + 1]]--;
            r++;
        }
        mn = min(mn, l - r);
    }
    cout << mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}