#include <iostream>

using namespace std;

const int MAXN = 4*200000;
long long int st[MAXN];
long long int a[MAXN];

void build(int u, int l, int r){
    if(l==r){
        st[u]=a[l];
        return;
    }
        int mid =  (l+r)/2;
        build(2*u+1, l, mid);
        build(2*u+2, mid+1, r);
        st[u] = st[2*u+1]+st[2*u+2];
}

void update(int u, int l, int r, int i, int x){
    if(l == r){
        a[i]=x;
        st[u]=x;
        return;
    }
    int mid = (l+r)/2;
    if(i <= mid){
        st[u]+=x-a[i];
        update(2*u+1, l, mid, i, x);
    }
    else{
        st[u]+=x-a[i];
        update(2*u+2, mid+1, r, i, x);
    }
}

int query(int u, int l, int r, int s, int e){
    if (s>r || e<l){
        return 0;
    }
    if(s<=l && r<=e){
        return st[u];
    }
    int mid = (l+r)/2;
    return query(2*u+1, l, mid, s, e) 
    + query(2*u+2, mid+1, r, s, e);
}

int main(){

    int n;
    int q;

    cin >> n >> q;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    build(0, 0, n-1);

    int x, b, c;
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