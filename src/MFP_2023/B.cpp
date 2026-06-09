#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      //ios_base::sync_with_stdio(false); cin.tie(NULL);
      //cout.tie(NULL);

      int n,mx=-1,mn=10000000010;
      vector<int> x;
      cin>>n;

      for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            x.push_back(tmp);
      }

      sort(x.begin(),x.end());

      

      for(int i=0;i<n/2;i++){
            mx=max(mx,(x[i]+x[n-1-i])/2);
      }

      cout<<mx<<"\n";

      return 0;
}
