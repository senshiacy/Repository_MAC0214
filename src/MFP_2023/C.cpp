#include <bits/stdc++.h> 
using namespace std; //evitar necessidade de “std::”
#define int long long

signed main() {
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cout.tie(NULL);

      //n flores, m convidados
      /*
      1 1 1 0 0 -> 1 de cada
      0 1 1 1 0 -> 1 de cada
      0 1 1 1 1 -> 2 de cada
      ---------
      1 3 3 2 1
      */


      double d,m;cin>>d>>m;
      double ida=sqrt(2*d*d);
      int rodadas=m/ida;
      double sobra=m-rodadas*ida;
      double cateto=sqrt(sobra*sobra/2);
      double x,y;
      if(rodadas%2==0){
            y=cateto;
      }
      else{
            y=d-cateto;
      }
      x=d*(double)rodadas+cateto;

      cout << setprecision(10) << fixed;
      cout<<x<<" "<<y<<"\n";
      


      





      return 0;
}