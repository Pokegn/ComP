#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;

    vector<bool> a(n+m);
    a[0]=0;
    int ni=n-1, mi=m;
    bool last=a[0];
    int ans1=0;

    for(int i=1; i<n+m; i++){
        if(i%2!=0){ //quiero cambiarlo
            if((last==0 ? mi : ni)>0){
                a[i]=(last==0 ? 1 : 0);
                (last==0 ? mi : ni)-=1;
            }
            else{
                a[i]=(last==0 ? 0 : 1);
                (last==0 ? ni : mi)-=1;
                ans1+=1;
            }
        }
        if(i%2==0){ //quiero igual
            if((last==0 ? ni : mi)>0){
                a[i]=(last==0 ? 0 : 1);
                (last==0 ? ni : mi)-=1;
                ans1+=1;
            }
            else{
                a[i]=(last==0 ? 1 : 0);
                (last==0 ? mi : ni)-=1;
            }
        }
        last=a[i];
    }
    
    a.clear();
    a[0]=1;
    ni=n, mi=m-1;
    int ans2=0;

    for(int i=1; i<n+m; i++){
        if(i%2!=0){ //quiero cambiarlo
            if((last==0 ? mi : ni)>0){
                a[i]=(last==0 ? 1 : 0);
                (last==0 ? mi : ni)-=1;
            }
            else{
                a[i]=(last==0 ? 0 : 1);
                (last==0 ? ni : mi)-=1;
                ans2+=1;
            }
        }
        if(i%2==0){ //quiero igual
            if((last==0 ? ni : mi)>0){
                a[i]=(last==0 ? 0 : 1);
                (last==0 ? ni : mi)-=1;
                ans2+=1;
            }
            else{
                a[i]=(last==0 ? 1 : 0);
                (last==0 ? mi : ni)-=1;
            }
        }
        last=a[i];
    }

    cout << max(ans1, ans2) << ' ' << n+m-1-(max(ans1, ans2));
}