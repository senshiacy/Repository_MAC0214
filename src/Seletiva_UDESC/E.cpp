#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'

char tab[2020][2020];
ll vert[2020][2020];
ll hor[2020][2020];

void solve() {
    ll N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tab[i][j];
        }
    }

    // pre-proc
    for(int i = 0; i < N; i++) {
        vert[i][M-1] = 1;
        for(int j = M-2; j >= 0; j--) {
            if(tab[i][j] == tab[i][j+1]) {
                vert[i][j] = vert[i][j+1] + 1;
            }
            else {
                vert[i][j] = 1;
            }
        }
    }

    for(int j = 0; j < M; j++) {
        hor[0][j] = 1;
        for(int i = 1; i < N; i++) {
            if(tab[i][j] == tab[i-1][j]) {
                hor[i][j] = hor[i-1][j] + 1;
            }
            else {
                hor[i][j] = 1;
            }
        }
    }

    ll cnt = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M-1; j++) {
            if(tab[i-1][j] == tab[i][j] and tab[i][j+1] == tab[i][j]) {
                cnt += (vert[i][j] - 1) * (hor[i][j] - 1);
            }
        }
    }

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}