#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long

signed main() {
   // ios_base::sync_with_stdio(false);
    
    string a[10];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];

    string final="";
    int erro=0;
    char tmp='A';
    for(int i=0;i<16;i++){
        char rsp='Z'+1;
        for(int j=0;j<6;j++){
            //cout<<i<<" "<<j<<" "<<a[j][i]<<"\n";
            if(a[j][i]>=tmp){
               // cout<<i<<" "<<j<<" "<<a[j][i]<<"\n";
                rsp=min(rsp,a[j][i]);
            }
        }
        if(rsp=='Z'+1){
            erro=1;
            break;
        }
        tmp=rsp;
        final+=rsp;
    }

    if(erro==1){
        cout<<"impossible\n";
        return 0;
    }

    //cout<<final<<"\n";

    int rsp=0;
    for(int i=0;i<16;i++){
        if(final[i]!=a[0][i]){
            rsp++;
        }
    }
    
    cout<<rsp<<'\n';
    return 0;
}
