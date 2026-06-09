#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

void solve() {
    int N, L;
    cin >> N >> L;

    vector<int> filhos(N);
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        filhos[i] = 100 - x;
    }
    
    sort(filhos.begin(), filhos.end());

    vector<int> acc(N, 0);
    acc[0] = filhos[0];
    for(int i = 1; i < N; i++) {
        acc[i] = acc[i - 1] + filhos[i];
    }

    for(int i = 0; i < N; i++) {
        if(acc[i] > L) {
            cout << i << endl;
            return;
        }
    }
    cout << N << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}