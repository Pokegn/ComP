#include <bits/stdc++.h>

using namespace std;

const int cocon = numeric_limits<int>::max();
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;

int dij(vector<vector<pair<int,int>>> &g, int k){
    int n= g.size();
    minheap<pair<int, int>> pq; // (s, v)
    vector<int> coste(n, -1);
    pq.push({0,0});

    pair<int,int> vactual;
    while(!pq.empty()){
        vactual = pq.top();
        pq.pop();
        if(vactual.second==k) return vactual.first;        

        if(coste[vactual.second] !=-1) continue;
        coste[vactual.second] = vactual.first;

        for(pair<int,int> &u: g[vactual.second]){
            pq.push({coste[vactual.second] + u.first, u.second});
        }
    }
    return -1;
}

int main(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> grafo(n);  // (w, v)

    int a,b;
    int w;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        grafo[a].push_back({w,b});
        grafo[b].push_back({w,a});
    }
    cout << dij(grafo, 3);

}