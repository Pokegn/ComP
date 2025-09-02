#include <bits/stdc++.h>

using namespace std;

void check();

int main(){

int n, m, k; cin >> n >> m >> k;
int xi, yi, xf, yf; cin >> xi >> yi >> xf >> yf;
int paso=2;
int ans=-1;
int s;

vector<pair<int, int>> movs(k);

for(int i=0; i<k; i++){
    cin >> movs[i].first;
}

vector<vector<int>> total(n, vector<int> (m,0));
vector<pair<int, int>> actual={ {xi, yi} };

total[xi][yi]=1;

while(actual.size()>0){
    s=actual.size();

    for(int i=0; i<s; i++){
        for(int j=0; j<10; j++){
            if(actual[i].first+movs[j].first>0 and actual[i].first+movs[j].first<=n and actual[i].second+movs[j].second>0 and actual[i].second+movs[j].second<=m){
                if(total[actual[i].first+movs[j].first][actual[i].second+movs[j].second]!=0){
                    total[actual[i].first+movs[j].first][actual[i].second+movs[j].second] = paso;
                    
                }
            }
        }

    }

}


cout << ans;

}

// - cuenta cuantos hay en actual
// - si entra en los parametros, mete ese movimiento de actual
// - quita cantidad que habia en actual
