#include <bits/stdc++.h>
 
using namespace std;

bool sort2(pair<int,int> c, pair<int,int> d)
{
       return c.second>d.second;
}

int main(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), sort2);
    sort(a.rbegin(), a.rend());

    bool share=true;
    int high=k, low=k-1;
    int shared=0;
    int x=0;
    while(share){
        if(high<n && a[high].first==a[k-1].first && a[high].second==a[k-1].second){
            cout << a[high].first << ' ' << a[high].second << endl;
            high++; shared++; x++;
        }
        if(low>=0 && a[low].first==a[k-1].first && a[low].second==a[k-1].second){
            cout << a[low].first << ' ' << a[low].second << endl;
            low--; shared++; x++;
        }
        if(x==0) share=false;
        if(high>=n and low<0) share=false;
        x=0;
    }

    cout << shared;
}