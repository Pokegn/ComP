#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n, s1, s2, ta=0, tb=0, x, k=0;
        cin >> n >> s1 >> s2;

        vector<int> a, b;

        vector<pair<int,int>> r(n);
        for(int j=0; j<n; j++){
            cin >> x;
            r[j] = {x,j};
        }

        sort(r.rbegin(), r.rend());

        for(int j = 0; j<n; j++){
            if (ta*s1+s1>tb*s2+s2){
                tb+=1;
                b.push_back(r[j].second);
            }
            else {
                ta+=1;
                a.push_back(r[j].second);
            }
        }
        cout << ta << ' ';
        for(int j = 0; j<ta; j++){
            cout << a[j]+1 << ' ';
        }
        cout << tb << ' ';
        for(int j = 0; j<tb; j++){
            cout << b[j]+1 << ' ';
        }
        cout << endl;
    }
}