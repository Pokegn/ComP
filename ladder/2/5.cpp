#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int x;

    cin >> x;
    int min=x;
    int max=x;
    int count=0;

    for(int i=1; i<n; i++){
        cin >> x;
        if(x>max){
            count+=1;
            max = x;
        }
        if(x<min){
            count+=1;
            min = x;
        }
    }

    cout << count;
}