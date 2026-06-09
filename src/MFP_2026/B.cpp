#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 1e6;
ll const INF = 1e18;

string A, B;
vector<ll> freqA(30, 0);
vector<ll> freqB(30, 0);
ll NA = 0, NB = 0;

void calcula(vector<ll> &v, string &s, ll k, ll &N) {
    for(auto a : s) {
        v[a - 'a'] += k;
        N += k;
    }
}

void solve() {
    int t;
    cin >> t;

    if(t == 1) {
        // Concatena k vezes a str s a SA
        ll k;
        string s;
        cin >> k >> s;
        calcula(freqA, s, k, NA);
        //cout << NA << endl;
    }
    if(t == 2) {
        // Concatena k vezes a str s a SP
        int k;
        string s;
        cin >> k >> s;
        calcula(freqB, s, k, NB);
        //cout << NB << endl;
    }
    if(t == 3) {
        // Envia a menor lexicograficamente menor
        ll currA = 0, currB = 0;
        for(int i = 0; i < 30; i++) {
            currA += freqA[i];
            currB += freqB[i];

            //cout << currA << " " << NA << endl;
            //cout << currB << " " << NB << endl;
            // Acabou a palavra da ADA
            if(currA == NA and currB != NB) {
                cout << "ADA" << endl;
                return;
            }
            // Acabou a palavra da PY
            if(currA != NA and currB == NB) {
                cout << "PY" << endl;
                return;
            }

            if(currA == NA and currB == NB) {
                // As letras existem
                if(freqA[i] > freqB[i]) {
                    cout << "PY" << endl;
                    return;
                }
                if(freqB[i] > freqA[i]) {
                    cout << "ADA" << endl;
                    return;
                }
                cout << "EMPATE" << endl;
                return;
            }

            /**
             * Ainda tem palavra pela frente
             */
            // PY tem uma letra menor
            if(freqA[i] == 0 and freqB[i] > 0) {
                cout << "PY" << endl;
                return;
            }
            // ADA tem uma letra menor
            if(freqB[i] == 0 and freqA[i] > 0) {
                cout << "ADA" << endl;
                return;
            }

            // As letras existem
            if(freqA[i] > freqB[i]) {
                cout << "ADA" << endl;
                return;
            }
            if(freqB[i] > freqA[i]) {
                cout << "PY" << endl;
                return;
            }
        }
        cout << "EMPATE" << endl;
        return;
    }

    // for(int i = 0; i < 26; i++) {
    //     cout << freqA[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++) {
    //     cout << freqB[i] << " ";
    // }
    // cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A;
    cin >> B;

    calcula(freqA, A, 1, NA);
    calcula(freqB, B, 1, NB);

    ll Q;
    cin >> Q;

    while(Q--)
        solve();
}