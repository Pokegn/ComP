#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int sum=0;
    int even=0;
    int x;

    for(int i=0; i<n; i++){
        cin>>x;
        if(x%2==0) even+=1;
        sum+=x;
    }

    if(sum%2==0){
        cout << even;
    }
    else{
        cout<<n-even;
    }
}