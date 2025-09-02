#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int x=s.size();
    int y;

    int c=0;
    vector<int> a(26,0);

    for(int i=0; i<x; i++){
        y=s[i]-'a';
        if(a[y]==0){
            a[y]=1;
            c+=1;
        }
    }

    if(c()%2 == 0) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
}