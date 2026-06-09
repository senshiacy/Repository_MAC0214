#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

ll const MAXN = 2e5 + 100;
ll const INF = 1e18;

ll n;
pll val[4 * MAXN];
ll arr[MAXN];

const ll neutral = 0;

pll merge(pll v1, pll v2) {
    if(v1.first > v2.first) {
        return v1;
    }
    else if(v1.first == v2.first) {
        if(v1.second > v2.second) {
            return v1;
        }
        else {
            return v2;
        }
    }
    return v2;
}

void build_rec(int id, int tl, int tr) {
    if(tl == tr) {
        val[id].first = arr[tl];
        val[id].second = tl;
    }
    else {
        int mid = (tl + tr)/2;
        build_rec(2*id, tl, mid);
        build_rec(2*id+1, mid+1, tr);
        val[id] = merge(val[2*id], val[2*id+1]);
    }
}

void build() {
    build_rec(1, 1, n);
}

pll query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl){
        return make_pair(neutral, -1);
    }
	if(l <= tl and tr <= r) {
        return val[id];
    }
	int mid = (tl+tr)/2;
	pll q1 = query_rec(2*id, tl, mid, l, r);
	pll q2 = query_rec(2*id+1, mid+1, tr, l, r);
    pll res = merge(q1, q2);
    return res;
}

pll query(int l, int r){
	return query_rec(1, 1, n, l, r);
}

void solve() {
    int mx = 0, idx = -1;
    cin >> n;

    int lim = 1;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build();
    map<int, int> freq;
    int L = 1;
    for(int i = 1; i <= n; i++) {
        if(freq.count(arr[i])) {
            L = max(L, freq[arr[i]] + 1);
        }
        freq[arr[i]] = i;
        pll ans = query(L, i);
        cout << ans.first << " " << ans.second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}