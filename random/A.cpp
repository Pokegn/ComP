#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, i; cin >> t;
    for(i+0; i<t; i++){
        string a,b;
        cin >> a >> b;

        int as=a.size()-1;
        int bs=b.size()-1;

        if (a[as]!=b[bs]){
            if (a[as]=='S') cout << '<' << endl;
            else if (b[bs]=='S') cout << '>' << endl;
            else if (a[as]=='M') cout << '<' << endl;
            else cout << '>' << endl;
        } else{
            if (a[as]=='S'){
                if (as>bs) cout << '<' << endl;
                if (as=bs) cout << '=' << endl;
                if (as<bs) cout << '>' << endl;
            }
            if (a[as]=='L'){
                if (as>bs) cout << '>' << endl;
                if (as=bs) cout << '=' << endl;
                if (as<bs) cout << '<' << endl;
            }
            if (a[as]=='M') cout << '=' << endl;
        }

    }
}
    