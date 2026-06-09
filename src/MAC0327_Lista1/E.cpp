#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define endl '\n'
#define pii pair<int, int>

ll const MAXN = 1e6;

ll solve() {
    int N;
    cin >> N;

    ll a[N + 2];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a[N] = 0;

    stack<pll> st;
    st.push({a[0], 0});
    ll mx = 0;

    for(int i = 1; i <= N; i++) {
        pll curr = {-1, -1};
        while(!st.empty() && st.top().first > a[i]) {
            curr = st.top();
            auto [h, x] = curr;
            mx = max(mx, h * (i - x));
            st.pop();
        }

        if(curr.first != -1) {
            st.push({a[i], curr.second});
        }
        st.push({a[i], i});
    }

    return mx;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
        cout << "Case " << i << ": " << solve() << endl;
}