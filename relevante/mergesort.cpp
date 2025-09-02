#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vlli a;

void MERGE(lli l, lli m, lli r){
    vlli temp(r);
    lli li = l;
    lli ri = m+1;
    lli i=l;
    while(li <= m && ri <= r){
        if((a[li]<=a[ri] && li<=m) || ri>r){
            temp[i] = a[li];
            i++;
            li++;
        }
        else{
            temp[i] = a[ri];
            i++;
            ri++;
        }
    }
    forn(j, l, r+1){
        a[j] = temp[j];
    }
}

void mergesort(lli l, lli r){
    lli m = (l+r)/2;
    mergesort(l, m);
    mergesort(m+1,r);
    MERGE(l, m, r);
}

void solve(){
    
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}