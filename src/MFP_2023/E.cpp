#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      //ios_base::sync_with_stdio(false); cin.tie(NULL);
      //cout.tie(NULL);

      int soma=0;
      int tmp;
      for(int i=0;i<7;i++){
            cin>>tmp;
            soma+=tmp;
      }

      cin>>tmp;
      if(tmp==0){
            if(soma%2==0){
                  cout<<"N?\n";
            }
            else{
                  cout<<"S\n";
            }
      }     
      else{
            if(soma%2==0){
                   cout<<"S\n";
            }
            else{
                  cout<<"N?\n";
            }
      } 

      return 0;
}