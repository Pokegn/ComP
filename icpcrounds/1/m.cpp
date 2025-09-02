#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ull = unsigned long long;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define lson  u<<1
#define rson u<<1|1
int msb(long long int x) { return 63 - __builtin_clzll(x);}
int msbint(int x) { return 31 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

    vector<bool> usado;
    const lli MAXN = 1000005;
    lli n, ki, a[MAXN], pos[MAXN+1];
    vlli lefti(MAXN+1, 0);
    vlli righti(MAXN+1, MAXN);
    vlli orden(MAXN+1);

    struct SegmentTree {
    struct Node {
        lli l,r;
        lli mi;
        lli ma;
    } st[4 * MAXN];

    void build(lli u, lli l, lli r){
        st[u].ma = 0;
        st[u].l = l;
        st[u].r = r;
        if(l == r){
            st[u].mi = a[l];
            return;
        }
        build(lson, l, (l+r)/2);
        build(rson, (l+r)/2+1, r);
        merge(u);
    }

    void merge(lli u){
        st[u].mi = min(st[lson].mi, st[rson].mi);
    }

    lli find_i(lli u, lli L, lli R, lli i){ //encuentra el indice con el valor i
        if(st[u].mi > i) return 0;
        if(st[u].l == st[u].r){
            return st[u].l;
        }
        
        lli mid = (st[u].l+st[u].r)/2;

        if(L>mid) return find_i(rson, L, R, i);
        if(R<=mid) return find_i(lson, L, R, i);
        
        lli res = find_i(lson,L,R,i);
        if(res) return res;
        else return find_i(rson, L,R,i);
    }

    pair<lli, lli> query(lli u, lli L, lli R){
        if (L <= st[u].l && st[u].r <= R) return {st[u].mi, 0};
        lli mid = (st[u].l + st[u].r) / 2;

        pair<lli, lli> res;

        if (L<= mid && R>mid){
            auto left = query(lson, L, R);
            auto right = query(rson, L, R);
            res.first = min(left.first, right.first);
            res.second =0;
        }
        else{
            if (L <= mid) {
                auto left = query(lson, L, R);
                res.first = left.first;
                res.second = 0;
            }
                if (R > mid) {
                auto right = query(rson, L, R);
                res.first = right.first;
                res.second = 0;
            }
        }
        return res;
    }

    void llena(lli l, lli r, lli k){
        if(r<l) return;

        lli mini = query(1, l, r).first;
        lli j = find_i(1, l, r, mini);

        while(orden[k]!=mini || usado[k]){
            k++;

        }
        usado[k] = true;

        pos[k] = j; //donde esta el k-esimo mayor
        lefti[k] = l-1; //puede ser 0
        righti[k] = r+1; //puede ser MAXN+1
        if(l==r) return;
        llena(l, j-1, k+1); llena(j+1, r, k+1);
    }

}seg;
    
void solve(){
    cin >> n >> ki;
    forn(i, 1, n+1) cin >> a[i];
    bool flag = true;
    forn(i, 2, n+1){
        if(a[i]!= a[1]) flag = false;
    }
    usado.assign(n+1, false);
    if(flag){
        cout << ki <<  ' ' << (ki*(ki+1))/2 << nl;
        return;
    }

    forn(i, 0, n+1) righti[i] = n+1;
    forn(i, 1, n+1) orden[i] = a[i];
    sort(orden.begin()+1, orden.begin()+n+1); 

    seg.build(1, 1, n); 

    seg.llena(1, n, 1);

    lli mcd = (lli)0;
    
    forn(i, 2, n+1){
        if(lefti[i]!=0){
            mcd = __gcd(orden[i]-a[lefti[i]], mcd);
        }
        if(righti[i]!=n+1){
            mcd = __gcd(orden[i]-a[righti[i]], mcd);
        }
    }
    mcd = abs(mcd);
    
    lli manyx = 0;
    lli ans = 0;
    queue<lli> posibles;
    for(lli i = 1; i*i<=mcd; i++){
        if(mcd%i == 0){
            posibles.push(i);
            if(i!=mcd/i) posibles.push(mcd/i);
        } 
    }

    while(!posibles.empty()){
        lli x = posibles.front();
        posibles.pop();
        x-=orden[1];
        if(x<=0) continue;
        if(x>ki) continue;
        flag = true;
        forn(i, 1, n+1){
            if(lefti[i]!=0 && (x+orden[i])%(x+a[lefti[i]]) != 0){
                flag = false;
            }

            if(righti[i]!=n+1 && (x+orden[i])%(x+a[righti[i]]) != 0){
                flag = false;
            }
        }
        if(flag){
            manyx++;
            ans+=x;
        }
    }
    cout << manyx << ' ' << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t; cin >> t;
    while(t--)
    solve();
    return 0;
}