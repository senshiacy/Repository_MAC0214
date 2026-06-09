#include <bits/stdc++.h> /// :)))

using namespace std;

#define int long long



signed main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    int mx=100;
    int soma=100;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        soma+=tmp;
        mx=max(mx,soma);
    }

    cout<<mx<<"\n";


    return 0;
}
 