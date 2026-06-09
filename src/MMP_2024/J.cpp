#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

void solve() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> d(N);
    for(int i = 0; i < N; i++) {
        cin >> d[i].first;
        d[i].second = 1; // Tá diminuindo
    }

    int cnt = 0;
    for(int i = 0; i < 201; i++) {
        // Dia i
        int ans = -1;
        for(int j = 0; j < N; j++) {
            if(d[j].second == 0 && d[j].first == D) {
                ans = j;
                break;
            }  
        }

        for(int j = 0; j < N; j++) {
            if(ans == -1 && d[j].first == D) {
                ans = j;
            }

            if(d[j].first == 0) { // Zerou
                d[j].first = 1;
                d[j].second = 0;
            }
            else if(d[j].second == 1) {
                d[j].first--;
            }
            else if(d[j].second == 0){
                d[j].first++;
            }
        }

        if(ans != -1) {
            d[ans].first = -1;
            d[ans].second = 2;
            cnt++;
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