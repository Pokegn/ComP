#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int x,y,a,b; cin >> x >> y >> a >> b;
    vector<pair<int, int>> ans;

    for(int xi=a; xi<=x; xi++){
        for(int yi=b; yi<=y; yi++){
            if(xi>yi) ans.push_back({xi,yi});
        }
    }

    cout << ans.size() << endl;

    for(int i=0; i<ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << endl;

}