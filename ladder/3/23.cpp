#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int x;
    int a=0, b=0;
    vector<int> v(n);
    int j=0;
    bool isP=0;

    for(int i=0; i<n; i++){
        cin >> x;
        v[i]=x;
        if(x>0) isP=1;
    }

    if(isP==1){
        vector<int> ans(n-2);
        for(int i=0; i<n; i++){
            if(v[i]>0 and a==0) a=v[i];
            else if(v[i]<0 and b==0) b=v[i];
            else{
                ans[j]=v[i];
                j+=1;
            }
        }

        cout << 1 << ' ' << b << endl;
        cout << 1 << ' ' << a << endl;
        cout << n-2 << ' ';
        for(int i=0; i<j; i++) cout << ans[i] << ' ';
        cout << endl;
    }


    if(isP==0){
        vector<int> ans(n-2);
        vector<int>ai(2,0);
        int k=0;
        for(int i=0; i<n; i++){
            if(v[i]<0 and ai[1]==0){
                ai[k]=v[i];
                k+=1;
            }
            else if(v[i]<0 and b==0) b=v[i];
            else{
                ans[j]=v[i];
                j+=1;
            }
        }

        cout << 1 << ' ' << b << endl;
        cout << 2 << ' ' << ai[0] << ' ' << ai[1] << endl;
        cout << n-3 << ' ';
        for(int i=0; i<j; i++) cout << ans[i] << ' ';
        cout << endl;

    }
}