#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;
ll const MOD =  1000000007;

vector<vector<ll>> mult_matrix(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    ll N = A.size();
    vector<vector<ll>> resp(N, vector<ll>(N));
    
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            resp[i][j] = 0;
            for(ll k = 0; k < N; k++) {
                resp[i][j] += ((A[i][k] * B[k][j]) % MOD);
            }
        }
    }

    return resp;
}

vector<vector<ll>> exp(vector<vector<ll>> &A, ll n) {
    // a^n
    if(n == 0){
        vector<vector<ll>> base(2, vector<ll>(2));
        base[0][0] = 1; base[0][1] = 0;
        base[1][0] = 0; base[1][1] = 1;
        return base;
    }

    vector<vector<ll>> tmp = exp(A, n/2);
    vector<vector<ll>> tmp2 = mult_matrix(tmp, tmp);
    if(n % 2 == 1) {
        return mult_matrix(tmp2, A);
    }
    return tmp2;
}

void solve() {
    /**
     * Fn+1  = A^n F1
     * Fn          F0
     * 
     * A = 1 1
     */

    vector<vector<ll>> A(2, vector<ll>(2)); 
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;

    ll n;
    cin >> n;
    vector<vector<ll>> resp = exp(A, n);
    cout << resp[1][0] % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}