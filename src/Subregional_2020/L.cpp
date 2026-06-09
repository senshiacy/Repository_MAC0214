#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long


int pal [30][30];
int pont [45][45];
signed main() {
    ios_base::sync_with_stdio(false);

    int l,r;
    cin>>l>>r;
    char mat[l+5][r+5];

    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            cin>>mat[i][j];
        }
    }

    int n;
    cin>>n;
    string s;
    int tm[n+5];
    for(int i=0;i<n;i++){
        cin>>s;
        int tam=s.size();
        for(int j=0;j<tam;j++){
            pal[i][s[j]-'A']++;

        }
        tm[i]=tam;

        /*for(int j=0;j<30;j++){
            cout<<pal[i][j];
        }
        cout<<"\n";*/
    }

    for(int p=0;p<n;p++){
        //cout<<p<<"\n";
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                if(pal[p][mat[i][j]-'A']>0){
                    //cout<<mat[i][j]<<" "<<tm[p]<<" "<<i<<" "<<j<<" "<<l<<" "<<r<<"\n";
                    //baixo
                    if(i+tm[p]<=l){
                        //cout<<"baixo\n";
                        int prov[30];
                        for(int k=0;k<30;k++){
                            prov[k]=0;
                        }
                        int fl=0;
                        for(int k=0;k<tm[p];k++){
                            prov[mat[i+k][j]-'A']++;
                            if(prov[mat[i+k][j]-'A']>pal[p][mat[i+k][j]-'A']){
                                fl=1;
                                break;
                            }
                        }
                        if(fl==0){
                            //cout<<"pt\n";
                            for(int k=0;k<tm[p];k++){
                                if(pont[i+k][j]==0){
                                    pont[i+k][j]=p+1;
                                }
                                else{
                                    if(pont[i+k][j]>0 && pont[i+k][j]!=p+1){
                                        pont[i+k][j]=-1;
                                    }
                                }
                                //cout<<pont[i+k][j];
                            }
                            //cout<<"\n";
                        }

                    }

                    //lado
                    if(j+tm[p]<=r){
                        //cout<<"lado\n";
                        int prov[30];
                        for(int k=0;k<30;k++){
                            prov[k]=0;
                        }
                        int fl=0;
                        for(int k=0;k<tm[p];k++){
                            prov[mat[i][j+k]-'A']++;
                            if(prov[mat[i][j+k]-'A']>pal[p][mat[i][j+k]-'A']){
                                fl=1;
                                break;
                            }
                        }
                        if(fl==0){
                            //cout<<"pt\n";
                            for(int k=0;k<tm[p];k++){
                                if(pont[i][j+k]==0){
                                    pont[i][j+k]=p+1;
                                }
                                else{
                                    if(pont[i][j+k]>0 && pont[i][j+k]!=p+1){
                                        pont[i][j+k]=-1;
                                    }
                                }
                            }
                        }
                    }
                    //diagonal frente
                    if(i+tm[p]<=l && j+tm[p]<=r){
                        //cout<<"diagonal\n";
                        int prov[30];
                        for(int k=0;k<30;k++){
                            prov[k]=0;
                        }
                        int fl=0;
                        for(int k=0;k<tm[p];k++){
                            prov[mat[i+k][j+k]-'A']++;
                            if(prov[mat[i+k][j+k]-'A']>pal[p][mat[i+k][j+k]-'A']){
                                fl=1;
                                break;
                            }
                        }
                        if(fl==0){
                            //cout<<"pt\n";
                            for(int k=0;k<tm[p];k++){
                                if(pont[i+k][j+k]==0){
                                    pont[i+k][j+k]=p+1;
                                }
                                else{
                                    if(pont[i+k][j+k]>0 && pont[i+k][j+k]!=p+1){
                                        pont[i+k][j+k]=-1;
                                    }
                                }
                            }
                        }
                    }
                    //diagonal trás
                    if(i+tm[p]<=l && j-tm[p]>=-1){
                        //cout<<"diagonal t\n";
                        int prov[30];
                        for(int k=0;k<30;k++){
                            prov[k]=0;
                        }
                        int fl=0;
                        for(int k=0;k<tm[p];k++){
                            prov[mat[i+k][j-k]-'A']++;
                            if(prov[mat[i+k][j-k]-'A']>pal[p][mat[i+k][j-k]-'A']){
                                fl=1;
                                break;
                            }
                        }
                        if(fl==0){
                            //cout<<"pt\n";
                            for(int k=0;k<tm[p];k++){
                                if(pont[i+k][j-k]==0){
                                    pont[i+k][j-k]=p+1;
                                }
                                else{
                                    if(pont[i+k][j-k]>0 && pont[i+k][j-k]!=p+1){
                                        pont[i+k][j-k]=-1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int soma=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            //cout<<pont[i][j];
            if(pont[i][j]==-1){
                soma++;
            }
        }
        //cout<<"\n";
    }

    cout<<soma<<"\n";

    return 0;
}