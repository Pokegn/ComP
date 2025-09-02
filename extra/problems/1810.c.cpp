#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;

    for(int i=0; i<t; i++){
        int n; cin >> n;
        long long int c,d; cin >> c >> d;
        vector<long long int> e(n);
        
        long long int x = 0;
        long long int cost = 0;
        long long int k = 0;
        for(int j=0; j<n; j++){
            cin >> e[j];
            }

        sort(e.begin(), e.end());
        for(int j=0; j<n; j++){
            if (j>0){
                if (e[j-1] == e[j]) x+=1;
            }
        }
        e.resize(unique(e.begin(), e.end()) - e.begin());

        cost = x;

        long long int smol = c*(n-x) + d;
        long long int total;
        long long int cerosizq;
        long long int unosder;

        //cout << n-x << endl;

        for(int j=0; j<(n-x); j++){
            cerosizq= e[j]-j-1;
            unosder= (n-x)-j-1;
            total = cerosizq*d + unosder*c;
            smol = min(smol, total);
            //cout << total << endl;
        }

        cout << smol + cost*c << endl;

    }

}