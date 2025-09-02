#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<int> left;
    vector<int> right;
    int l, r;
    int x;

    for(int i=1; i<=n; i++){
        cin >> x; //LEFT
        if(i==1 or x<l){
            left.clear();
            left.push_back(i);
            l=x;
        }
        else if(x==l){
            left.push_back(i);
        }

        cin >> x; //RIGHT
        if(i==1 or x>r){
            right.clear();
            right.push_back(i);
            r=x;
        }
        else if(x==r){
            right.push_back(i);
        }
    }
    
    int li=0, ri=0;
    bool ans=0;
    while(li<left.size() && ri<right.size() && !ans){
        if(left[li]<right[ri]) li++;
        else if(left[li]>right[ri]) ri++;
        else if(left[li]==right[ri]){
            x=left[li];
            ans=1;
        }
    }

    if(ans) cout << x;
    else cout << -1;
}