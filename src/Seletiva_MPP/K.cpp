#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long

signed main() {
   // ios_base::sync_with_stdio(false);
    
    // horas
    //60 graus, cada um por minuto

    // minutos
    //360 graus, 6*60 graus sao um minuto

    int h,m;
    cin>>h>>m;
    double tmp=double(m)/double(6);//qual minuto é
    int verifica=h%30;

    if(verifica*2==tmp){
        cout<<"yes\n";
        return 0;
    }



    cout<<"no\n";

    return 0;
}