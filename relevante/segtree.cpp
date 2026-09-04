//https://cses.fi/problemset/task/1648
#include <iostream>
#define ll long long
using namespace std;

const int MAXN = 4*200000;
ll st[MAXN];
ll a[MAXN];

void build(ll u, ll l, ll r){
    if(l==r){
        st[u]=a[l];
        return;
    }
        ll mid =  (l+r)/2;
        build(2*u+1, l, mid);
        build(2*u+2, mid+1, r);
        st[u] = st[2*u+1]+st[2*u+2];
}

void update(ll u, ll l, ll r, ll i, ll x){
    if(l == r){
        a[i]=x;
        st[u]=x;
        return;
    }
    ll mid = (l+r)/2;
    if(i <= mid){
        st[u]+=x-a[i];
        update(2*u+1, l, mid, i, x);
    }
    else{
        st[u]+=x-a[i];
        update(2*u+2, mid+1, r, i, x);
    }
}

ll query(ll u, ll l, ll r, ll s, ll e){
    if (s>r || e<l){
        return 0;
    }
    if(s<=l && r<=e){
        return st[u];
    }
    ll mid = (l+r)/2;
    return query(2*u+1, l, mid, s, e) 
    + query(2*u+2, mid+1, r, s, e);
}

int main(){
    ll n;
    ll q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    build(0, 0, n-1);

    ll x, b, c;
    for(int i=0; i<q; i++){
        cin >> x >> b >> c;
        if(x==1){
            update(0, 0, n-1, b-1, c);
        }
        else{
            cout << query(0, 0, n-1, b-1, c-1) << endl;
        }
    }

    return 0;
}