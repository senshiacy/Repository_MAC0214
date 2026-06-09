#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long



signed main() {
    ios_base::sync_with_stdio(false);

    string s;
    int pontl=0;
    int pontr=0;
    int matl=0;
    int matr=0;
    int lado=0;//s=l, if==1, s=r;
    int win=0;
    cin>>s;
    char c;
    int tam=s.size();
    for(int i=0;i<tam;i++){
        c=s[i];
        if(c=='S' && win==0){
            if(lado==0){
                pontl++;
                lado=0;
                if(pontl==10 || (pontl>=5 && pontl-pontr>=2)){//ganha o match
                    matl++;
                    pontl=0;
                    pontr=0;
                    lado=0;
                    if(matl==2){
                        win=1;
                    }
                }
            }
            else{
                pontr++;
                lado=1;
                if(pontr==10 || (pontr>=5 && pontr-pontl>=2)){//ganha o match
                    matr++;
                    pontl=0;
                    pontr=0;
                    lado=1;
                    if(matr==2){
                        win=1;
                    }
                }
            }
        }
        else{
            if(c=='R' && win==0){
                if(lado==1){
                    pontl++;
                    lado=0;
                    if(pontl==10 || (pontl>=5 && pontl-pontr>=2)){//ganha o match
                        matl++;
                        pontl=0;
                        pontr=0;
                        lado=0;
                        if(matl==2){
                            win=1;
                        }
                    }
                }
                else{
                    pontr++;
                    lado=1;
                    if(pontr==10 || (pontr>=5 && pontr-pontl>=2)){//ganha o match
                        matr++;
                        pontl=0;
                        pontr=0;
                        lado=1;
                        if(matr==2){
                            win=1;
                        }
                    }
                }
            }
            else{//c==Q
                if(win==0){
                    if(lado==0){
                        cout<<matl<<" ("<<pontl<<"*) - "<<matr<<" ("<<pontr<<")\n";
                    }
                    else{
                        cout<<matl<<" ("<<pontl<<") - "<<matr<<" ("<<pontr<<"*)\n";
                    }
                }
                else{
                    if(matl==2){
                        cout<<matl<<" (winner) - "<<matr<<"\n";
                    }
                    else{
                        cout<<matl<<" - "<<matr<<" (winner)\n";
                    }
                }
            }
        }
    }


    return 0;
}