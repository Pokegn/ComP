//https://cses.fi/problemset/task/1648
#include <iostream>

using namespace std;

void build(int u, int l, int r, long long int st[], long long int a[]){
    if(l==r){
        st[u]=a[l];
        return;
    }
        int mid =  (l+r)/2;
        build(2*u+1, l, mid, st, a);
        build(2*u+2, mid+1, r, st, a);
        st[u] = st[2*u+1]+st[2*u+2];
}

void update(int u, int l, int r, int i, int x, long long int st[], long long int a[]){
    if(l == r){
        a[i]=x;
        st[u]=x;
        return;
    }
    int mid = (l+r)/2;
    if(i <= mid){
        st[u]+=x-a[i];
        update(2*u+1, l, mid, i, x, st, a);
    }
    else{
        st[u]+=x-a[i];
        update(2*u+2, mid+1, r, i, x, st, a);
    }
}

int query(int u, int l, int r, int s, int e, long long int st[], long long int a[]){
    if (s>r || e<l){
        return 0;
    }
    if(s<=l && r<=e){
        return st[u];
    }
    int mid = (l+r)/2;
    return query(2*u+1, l, mid, s, e, st, a) 
    + query(2*u+2, mid+1, r, s, e, st, a);
}

int main(){

    int n;
    int q;

    cin >> n >> q;
    long long int st[n*4];
    long long int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    build(0, 0, n-1, st, a);

    int x, b, c;
    for(int i=0; i<q; i++){
        cin >> x >> b >> c;
        if(x==1){
            update(0, 0, n-1, b-1, c, st, a);
        }
        else{
            cout << query(0, 0, n-1, b-1, c-1, st, a) << endl;
        }
    }

    return 0;
}