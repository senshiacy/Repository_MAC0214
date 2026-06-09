/// Attempt

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll const MAXN = 2e6;
ll const INF = 1e18;

vector<int> primes;

void crivo(int n){
	vector<bool> is_composite(n+1, false);
	for(int i=2; i * i <= n; i++){
		if(not is_composite[i]){
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				is_composite[j] = true;
		}
	}
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    bool order = true;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            order = false;
        }
    }

    if(order) {
        cout << "Bob" << endl;
        return;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int curr = a[i], j = 0;
        int pass = 0;
        while(curr > 1 && j < primes.size()) {
            if(curr > 1 && curr % primes[j] == 0) {
                pass++;
            }
            while(curr > 1 && curr % primes[j] == 0) {
                curr /= primes[j];
                ans.push_back(primes[j]);
            }
            j++;
        }
        if(pass >= 2) {
            cout << "Alice" << endl;
            return;
        }
    }

    for(int i = 1; i < ans.size(); i++) {
        if(ans[i] < ans[i - 1]) {
            cout << "Alice" << endl;
            return;
        }
    }

    int mov = ans.size() - n;
    if(mov & 1 == 0) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1ll;
    cin >> t;

    crivo(MAXN);

    while(t--)
        solve();
}