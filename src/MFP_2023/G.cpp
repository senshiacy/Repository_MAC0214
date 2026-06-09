#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cout.tie(NULL);

      // G) n flores, m convidados
      /*
      1 1 1 0 0 -> 1 de cada
      0 1 1 1 0 -> 1 de cada
      0 1 1 1 1 -> 2 de cada
      ---------
      1 3 3 2 1


      0 1 0 1 0

      */

      //F)
      /*
      apenas mensagens com A-H

      */


      int n,m;
      cin>>n>>m;
      for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
      }

      for(int i=0;i<n;i++){
            if(i%2==0){
                  cout<<0;
            }
            else{
                  cout<<1;
            }

      }

      cout<<"\n";


      





      return 0;
}
