#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      //ios_base::sync_with_stdio(false); cin.tie(NULL);
      //cout.tie(NULL);

      double m1,m2,x1,x2,f;

      cin>>m1>>m2>>x1>>x2>>f;

      double d=abs(x2-x1);

      double g= f*d*d/m1/m2;
      cout << setprecision(8) << fixed << g << endl;

      return 0;
}