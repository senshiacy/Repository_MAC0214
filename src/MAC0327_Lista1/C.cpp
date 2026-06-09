#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

int n;
vector<int> a; // value -> index
set<int> pos;
map<int, set<int>> idxs;

void query(int c) {
    set<int> st = idxs[c];
    if(st.size() > 1) {
        // The first occ
        int ini = *st.begin(), fim = *st.rbegin();

        while(!st.empty() && !pos.empty() && pos.find(ini) == pos.end()) { // Enqto não for vazio e existir a occ do início
            // Erase
            st.erase(ini); // Procura o próximo
            if(!st.empty())
                ini = *st.begin();
            else
                ini = -1;
        }

        while(!st.empty() && !pos.empty() && pos.find(fim) == pos.end()) { // Enqto não for vazio e existir a occ do fim
            // Erase
            st.erase(fim);
            if(!st.empty())
                fim = *st.rbegin();
            else
                fim = -1;
        }
        idxs[c] = st;

        //cout << c << ": ";
        //for(auto s : st) {
        //    cout << s << " ";
        //}
        //cout << endl;
        //return;

        if(ini != -1 && ini != fim) {
            auto it_start = pos.upper_bound(ini);
            auto it_end = pos.upper_bound(fim);
            pos.erase(it_start, it_end);
        }
    }
}

void solve() {
    cin >> n;
    /**
     * [7, 1, 7, 1, 23, 9, 23, 1] -> [7,]
     * [0, 0, 7], [1, 1, 1], [2, 2, 7], [3, 3, 1], [4, 4, 23],
     * [5, 5, 9], [6, 6, 23], [7, 7, 1]
     * 1 : 1, 3, 7
     * 7 : 0, 2,
     * 9 : 5
     * 23 : 4, 6
     * [7]
     * 0, 1, 2, 3, 4, 5, 6, 7
     * 
     * 
     */
    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos.insert(i);
        idxs[a[i]].insert(i);
    }

    int q;
    cin >> q;
    while(q--) {
        int c; cin >> c;
        query(c);
    }

    int i = 0;
    pos.insert(n);
    for(auto s : pos) {
        for(int j = i; j < s; j++) {
            cout << a[i] << " ";
        }
        i = s;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}