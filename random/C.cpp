#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[200000];
    int t; cin >> t;

    int i; for(i=0; i<t; i++){
        long long int n; cin >> n;
        int j; for(j=0; j<n; j++){
            cin >> a[j];
        }

        int x,y;
        long long int s;
        x=0;
        y=0;

        for(x<n; x++;){
            while((x-a[y])>=0 and y<n) y+=1;
            s=(y-x); 
        }

    }