#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int N;
    cin >> N;

    vector<stack<int>> pilhas(N);
    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for(int j = 0; j < K; j++) {
            int L;
            cin >> L;
            pilhas[i].push(L);
        }
    }

    if(N == 1 || N >= 3) { // Heuristica de que joga todo mundo da pilha para a segunda
        cout << "S" << endl;
        return;
    }

    while(!pilhas[1].empty()) {
        pilhas[0].push(pilhas[1].top());
        pilhas[1].pop();
    }

    int topo;
    if(!pilhas[0].empty()) {
        topo = pilhas[0].top();
        pilhas[0].pop();
    }
    while(!pilhas[0].empty()) {
        if(topo < pilhas[0].top()) {
            cout << "N" << endl;
            return;
        }
        topo = pilhas[0].top();
        pilhas[0].pop();
    }
    cout << "S" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}