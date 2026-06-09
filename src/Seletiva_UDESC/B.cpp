#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int H, A, B;
    cin >> H >> A >> B;
    if(H < A || H > B) {
        cout << "NAO" << endl;
    }
    else { 
        cout << "SIM" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}