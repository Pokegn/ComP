#include <bits/stdc++.h>

using namespace std;

bool isx(vector<int> a, int s, int x){
    for(int i=0; i<s; i++){
        if(a[i]==x) return 1;
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    int x;
    int current=1;
    
    vector<int> a(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }

    for(int i=0; i<k; i++){
        x=0;
        while(x<n-1){
            if(isx(a,k,current)) current+=1;
            else{
                cout << current << ' ';
                current+=1;
                x+=1;
            }
        }
        cout << a[i] << endl;
    }
}