#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<bool> a(9,1);
    int x;
    
    for(int i=0; i<9; i++){
        cin >> x;

        if(x%2==1){
            a[i]= ! a[i];

            if(i>2) a[i-3]= ! a[i-3];
            if(i%3!=0) a[i-1]= ! a[i-1];
            if(i<6) a[i+3]= !a[i+3];
            if(i%3!=2) a[i+1]=!a[i+1];
        }
    }

    for(int i=0; i<9; i++){
        cout << a[i];
        if(i%3==2) cout << endl;

        
    }
}