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


    const ull MAXN = 1000005;
    ull n, q, a[MAXN];

    struct SegmentTree {
    struct Node {
        ull l,r;
        ull v,s,t;  // & del rango
        bool flag;
    } st[4 * MAXN];

    void build(ull u, ull l, ull r){
        st[u].l = l;
        st[u].r = r;
        st[u].t = (~0ull);
        if(l == r){
            st[u].v = a[l];
            st[u].s = (~0ull);
            st[u].flag = true;
            return;
        }
        build(lson, l, (l+r)/2);
        build(rson, (l+r)/2+1, r);
        merge(u);
    }

    void merge(ull u){
        st[u].v = ((st[lson].v) & (st[rson].v));
        st[u].s = (((st[lson].v)&(st[rson].s))|((st[lson].s)&(st[rson].v)));        
    }

    void push(ull u) {
        if (st[u].t != (~0ull)) {
            st[lson].v&= st[u].t;
            st[lson].t&= st[u].t;
            st[rson].v&= st[u].t;
            st[rson].t&= st[u].t;

            if(!st[lson].flag) st[lson].s&=st[u].t;
            if(!st[rson].flag) st[rson].s&=st[u].t;
                
            st[u].t = (~0ull);
        }
    }
    
    void updaterange(ull u, ull L, ull R, ull x){
        if(L<=st[u].l && R>=st[u].r){
            st[u].v &= x;
            st[u].t &= x;
            if(!st[u].flag) st[u].s &= x;
            return;
        }

        push(u);
        ull mid = (st[u].l+st[u].r)/2;
        if (L <= mid) updaterange(lson, L, R, x);
        if (R > mid) updaterange(rson, L, R, x);
        merge(u);
    }

    void change(ull u, ull i, ull x){
        if(st[u].l == i && i == st[u].r){
            st[u].v = x;
            return;
        }
        push(u);
        ull mid = (st[u].l+st[u].r)/2;
        if(i<=mid) change(lson, i, x);
        else change(rson, i, x);
        merge(u);
    }

    ull find_i(ull u, ull L, ull R, ull bit){
        if((st[u].v>>bit)&1) return 0;
        if(st[u].l == st[u].r){
            return st[u].l;
        }
        
        ull mid = (st[u].l+st[u].r)/2;

        if(L>mid) return find_i(rson, L, R, bit);
        if(R<=mid) return find_i(lson, L, R, bit);
        
        ull res = find_i(lson,L,R,bit);
        if(res) return res;
        else return find_i(rson, L,R,bit);
    }
    
    pair<ull, ull> query(ull u, ull L, ull R){
        if (L <= st[u].l && st[u].r <= R) return {st[u].v, st[u].s};
        ull mid = (st[u].l + st[u].r) / 2;

        pair<ull, ull> res;
        push(u);

        if (L<= mid && R>mid){
            auto left = query(lson, L, R);
            auto right = query(rson, L, R);
            res.first = left.first&right.first;
            res.second = (left.second&right.first)|(left.first&right.second);
        }
        else{
            if (L <= mid) {
                auto left = query(lson, L, R);
                res.first = left.first;
                res.second = left.second;
            }
                if (R > mid) {
                auto right = query(rson, L, R);
                res.first = right.first;
                res.second = right.second;
            }
        }
        return res;
    }

}seg;
    
void solve(){
    cin >> n >> q;
    forn(i, 1, n+1) cin >> a[i];
    ull op;
    ull l, r, x, u;

    seg.build(1, 1, n);
    
    forn(j, 0, q){
        //forn(i, 0, 4*n) cout << seg.st[i].s << ' ';
        //cout << nl;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            seg.updaterange(1, l, r, x);
        }
        else if(op == 2){
            cin >> u >> x;
            seg.change(1, u, x);
        }
        else if(op == 3){
            cin >> l >> r;
            
            pair<ull,ull> gf = seg.query(1, l, r);
            ull g = gf.first;
            ull f = gf.second;

            if(g == f){
                cout << g << nl;
                continue;
            }

            rof(i, 63, 0){ 
                //cout << f << ' ' << g << ' ';
                if(((f>>i)&1)&&(!((g>>i)&1))) {
                    ull coso = seg.find_i(1,l,r,i);
                    ull ans = (~0ull);
                    if(coso!=l) ans&=seg.query(1,l,coso-1).first;
                    if(coso!=r) ans&=seg.query(1,coso+1,r).first;
                    cout << ans << nl;
                    break;
                }
            }
        } 
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}