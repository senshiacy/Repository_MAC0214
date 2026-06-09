#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long

signed main() {
   // ios_base::sync_with_stdio(false);
    
    
    unordered_map<string,int> palavras;

    string s; cin>>s;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        palavras[tmp]=size(tmp);
    }

    int tam=s.size();
    //cout<<tam<<"\n";
    vector <int> G[tam+50];
    vector <int> controle(tam+50);
    controle[0]=1;

    for(int i=0;i<tam;i++){
        if(controle[i]==1){
            for(int j=6;j<=10;j++){
                //cout<<s.substr(i,j)<<"\n";
                if(palavras[s.substr(i,j)]){
                    controle[i+j]=1;
                }
            }
        }
    }


   /* for(int i=0;i<tam+1;i++){
        cout<<i<<" "<<controle[i]<<"\n";
    }*/


    if(controle[tam]==1){
        cout<<"yes\n";
        return 0;
    }

    cout<<"no\n";
    return 0;
}
