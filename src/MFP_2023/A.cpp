#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cout.tie(NULL);

      int t;cin>>t;

      int amigos[105];


      for(int loops=0;loops<t;loops++){
            int n;cin>>n;
            for(int i=1;i<=n;i++){
                  cin>>amigos[i];
            }

            for(int i=1;i<=n;i++){
                  int tmp=i;
                  do{
                        cout<<tmp<<" ";
                        tmp=amigos[tmp];
                  }while(tmp!=i);
                  cout<<"\n";

            }
      }
      

      return 0;
}
