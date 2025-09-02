#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    char last,y,z;
    int c=0;

    cin >> last;
    for(int i=1; i<n; i++){
        cin >> y;
        if(last==y){
            c+=1;
        }
        last=y;
    }
    cout << c;
}
