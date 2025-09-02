//https://cses.fi/problemset/task/1648
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

void build(int u, int l, int r, long long int st[], long long int a[]){
    if(l==r){
        st[u]=a[l];
        return;
    }
        int mid =  (l+r)/2;
        build(2*u+1, l, mid, st, a);
        build(2*u+2, mid+1, r, st, a);
        st[u] = __gcd(st[2*u+1],st[2*u+2]);
}

int query(int u, int l, int r, int s, int e, long long int st[], long long int a[]){
    if (s>r || e<l){
        return 0;
    }
    if(s<=l && r<=e){
        return st[u];
    }
    int mid = (l+r)/2;
    return __gcd(query(2*u+1, l, mid, s, e, st, a), 
    query(2*u+2, mid+1, r, s, e, st, a));
}

int main(){

    lli n;
    cin >> n;
    long long int st[n*4];
    long long int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    build(0, 0, n-1, st, a);

    lli xd;
    lli maxi = 0;
    forn(i, 0, n){
        xd = __gcd(query(0, 0, n-1, 0, i-1, st, a), query(0, 0, n-1, i+1, n-1, st, a));
        maxi = max(xd, maxi);
    }

    cout << maxi << nl;

    return 0;
}