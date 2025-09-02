#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    string s; cin >> s;
    int a='a';
    int b='A';
    int count=0;
    int size=s.length();

    vector<int> r(size,0);

    for(int i=0; i<size; i++){
        if(s[i]>'Z'){
            count+=1;
            r[i]=1;
        }
        else count-=1;
    }

    if(count>=0){
        for(int i=0; i<size; i++){
            if(r[i]==0){
                s[i]=s[i]+a-b;
            }
        }
    }
    if(count<0){
        for(int i=0; i<size; i++){
            if(r[i]==1){
                s[i]=s[i]-a+b;
            }
        }
    }
    
    for(int i=0; i<size; i++){
        cout << s[i];
    }

}