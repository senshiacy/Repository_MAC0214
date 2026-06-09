#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

void solve() {
    int N;
    cin >> N;
    int D, L, R, C;
    bool valido = true;

    bool Tab[12][12];
    for(int i  = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            Tab[i][j] = false;
        }
    }

    while(N--) {
        cin >> D >> L >> R >> C;
        if(D == 0 and C + L - 1 > 10) {
            valido = false;
        }
        if(D == 1 and R + L - 1 > 10) {
            valido = false;
        }
        if(valido) {
            if(D == 0) {
                for(int i = 0; i < L; i++) {
                    if(Tab[R][C + i]) {
                        valido = false;
                    }
                    else {
                        Tab[R][C + i] = true;
                    }
                }
            }
            else {
                for(int i = 0; i < L; i++) {
                    if(Tab[R + i][C]) {
                        valido = false;
                    }
                    else {
                        Tab[R + i][C] = true;
                    }
                }   
            }
        }   
    }

    if(valido == true) {
        cout << "Y" << endl;
    }
    else {
        cout << "N" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}