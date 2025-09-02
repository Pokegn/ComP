#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
 
using namespace std;
 
int main(){

int n, m, k; cin >> n >> m >> k;
int l,r,d;
vector<int> a(n+1);
vector<pair<int, int>> oprange(m+1);
vector<int> opd(m+1);
vector<int> opuses(m+1, 0);

for(int i=0; i<n; i++){
    cin >> a[i+1];
}

for(int i=0; i<m; i++){
    cin >> oprange[i+1].first >> oprange[i+1].second >> opd[i+1];
}

for(int i=1; i<n+1; i++){
    opsumsum[i]=opsumsum[i-1]+opsum[i];
    cout << opsumsum[i] << ' ';
}
cout << endl;

for(int i=0; i<k; i++){
    int x, y; cin >> x >> y;
    cout << a[i]+opsumsum[y]-opsumsum[x-1] << endl;
}

vector<int> ans(n+1);


}