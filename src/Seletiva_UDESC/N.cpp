#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int M;
    cin >> M;
    vector<int> a(M);
    for(int i = 0; i < M; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1; i < M - 1; i++) {
        if(a[i] > a[i-1] and a[i] > a[i+1]) {
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