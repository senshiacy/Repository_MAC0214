#include <iostream>
#include <string>

using namespace std;

void solve() {
    string S;
    cin >> S;

    if(S.size() % 5 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}