#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    /**
     * 1, 2, ..., N
     * 1, 2, ..., M
     */
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1, 0);
    vector<int> B(M + 1, 0);

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[a]++;
        B[b]++;
    }

    for(int i = 1; i <= M; i++) {
        cout << B[i] - A[i] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}