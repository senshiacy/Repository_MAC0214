#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'

ll const MAXN = 2e6;
ll const INF = 1e18;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Setagem dos pointers
    int l = x, r = y;

    // Mínimo do middle
    int mn = n + 10;
    queue<int> q;
    for(int i = l; i < r; i++) {
        q.push(p[i]);
        mn = min(mn, p[i]);
    }
    while(q.front() != mn) {
        q.push(q.front());
        q.pop();
    }

    // Maximo do externo
    queue<int> s1, s2; 
    for(int i = 0; i < l; i++) {
        s1.push(p[i]);
    }
    for(int i = r; i < n; i++) {
        s2.push(p[i]);
    }

    queue<int> ans;
    while(!s1.empty() && s1.front() < q.front()) {
        ans.push(s1.front());
        s1.pop();
    }
    while(s1.empty() && !s2.empty() && s2.front() < q.front()) {
        ans.push(s2.front());
        s2.pop();
    }
    while(!q.empty()) {
        ans.push(q.front());
        q.pop();
    }
    while(!s1.empty()) {
        ans.push(s1.front());
        s1.pop();
    }
    while(!s2.empty()) {
        ans.push(s2.front());
        s2.pop();  
    }

    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    /*
    // Merge
    if(!s1.empty() && s1.front() < q.front()) {
        while(!s1.empty() && s1.back() > q.front()) {
            s2.push_front(s1.back());
            s1.pop_back();
        }
        while(!s2.empty() && s2.front() < q.front()) {
            s1.push_back(s2.front());
            s2.pop_front();
        }
        // Print
        while(!s1.empty()) {
            cout << s1.front() << " ";
            s1.pop_front();
        }
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    else if(s1.empty() && !s2.empty() && s2.front() < q.front()) {
        while(!s2.empty() && s2.front() < q.front()) {
            cout << s2.front() << " ";
            s2.pop_front();
        }
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    else {
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        while(!s1.empty()) {
            cout << s1.front() << " ";
            s1.pop_front();
        }
    }

    while(!s2.empty()) {
        cout << s2.front() << " ";
        s2.pop_front();
    }
    cout << endl;
    */
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1ll;
    cin >> t;

    while(t--)
        solve();
}