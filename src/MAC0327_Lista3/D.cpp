/**
 * Sei que tudo faz parte
 * Do que pretendemos conquistar
 * Na vida a luta é uma arte
 * E a gente vai chegar lá !
 * Independência ou morte !
 */

#include <iostream>
#include <array>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1010;
ll const MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> lcs(max(n, m) + 1, vector<ll>(max(n, m) + 1, 0));
    
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++) {
        cin >> b[j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    stack<int> seq;
    int i = n, j = m;
    while(i >= 1 && j >= 1) {
        //cout << i << " " << j << endl;
        if(a[i] == b[j]) {
            seq.push(a[i]);
            i--; j--;
        }
        else if(lcs[i][j] == lcs[i - 1][j]){
            i--;
        }
        else {
            j--;
        }
    }

    cout << lcs[n][m] << endl;
    while(!seq.empty()) {
        cout << seq.top() << " ";
        seq.pop();
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}