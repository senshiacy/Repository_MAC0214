#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

long double distance(vector<int> &v) {
    int n = v.size();
    long double mid = 0;
    sort(v.begin(), v.end());

    if(n % 2 == 1) {
        mid = v[n/2];
    }
    else {
        mid = (v[n/2] + v[n/2-1])/2;
    }

    long double dist = 0;
    for(int i = 0; i < n; i++) {
        dist += abs((long double) v[i] - mid);
    }

    return dist;
}

void solve() {
    int N;
    cin >> N;

    // Mapeia na rua r os passageiros
    map<int, vector<int>> rua;
    for(int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        rua[r].push_back(c);
    }

    ll dist = 0;
    for(auto [r, v] : rua) {
        dist += distance(v);
    }

    cout << dist << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}