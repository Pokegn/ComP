#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lson u<<1
#define rson u<<1|1
#define pii pair<ull,ull>

using namespace std;
const int N=1e6+10;
const ull inf=(~0ull);
int n,q;
ull a[N];
struct node {
	int l,r;
	ull v,s,t;
	bool flg;
} tr[N<<2];

void pushup(int u) {
	tr[u].v=(tr[lson].v&tr[rson].v);
	tr[u].s=((tr[lson].v&tr[rson].s)|(tr[lson].s&tr[rson].v));
	return;
}

void pushdown(int u) {
	if(tr[u].t!=inf) {
		tr[lson].t&=tr[u].t;
		tr[rson].t&=tr[u].t;
		tr[lson].v&=tr[u].t;
		tr[rson].v&=tr[u].t;
		if(!tr[lson].flg) tr[lson].s&=tr[u].t;
		if(!tr[rson].flg) tr[rson].s&=tr[u].t;
		tr[u].t=inf;
	}
	return ;
}

void build(int u,int l,int r) {
	tr[u].l=l,tr[u].r=r,tr[u].t=inf;
	if(l==r) {
		tr[u].v=a[l];
		tr[u].s=inf;
		tr[u].flg=true;
		return;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(u);
	return;
}

void modify1(int u,int l,int r,ull v) {
	if(tr[u].l>=l&&tr[u].r<=r) {
		tr[u].v&=v;
		tr[u].t&=v;
		if(!tr[u].flg) tr[u].s&=v;
		return;
	}
	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid) modify1(lson,l,r,v);
	if(r>mid) modify1(rson,l,r,v);
	pushup(u);
	return ;
}

void modify2(int u,int p,ull v) {
	if(tr[u].l==p&&tr[u].r==p) {
		tr[u].v=v;
		return ;
	}
	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	if(p<=mid) modify2(lson,p,v);
	if(p>mid) modify2(rson,p,v);
	pushup(u);
	return ;
}

pii qry1(int u,int l,int r) {
	if(tr[u].l>=l&&tr[u].r<=r) {
		pii ret={tr[u].v,tr[u].s};
		return ret;
	}
	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l>mid) return qry1(rson,l,r);
	if(r<=mid) return qry1(lson,l,r);
	pii retL=qry1(lson,l,r),retR=qry1(rson,l,r);
	pii ret;
	ret.first=(retL.first&retR.first);
	ret.second=((retL.first&retR.second)|(retL.second&retR.first));
	return ret;
}

int qry2(int u,int l,int r,int p) {
	if((tr[u].v>>p)&1) return 0;
	if(tr[u].l==tr[u].r) return tr[u].l;
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l>mid) return qry2(rson,l,r,p);
	if(r<=mid) return qry2(lson,l,r,p);
	int ret=qry2(lson,l,r,p);
	if(ret) return ret;
	else return qry2(rson,l,r,p);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	build(1,1,n);
	while(q--) {
        for(int i=0; i<4*n; i++) cout << tr[i].s << ' ';
        cout << '\n';
		int opt;
		cin>>opt;
		if(opt==1) {
			int l,r;
			ull x;
			cin>>l>>r>>x;
			modify1(1,l,r,x);
		} else if(opt==2) {
			int p;
			ull x;
			cin>>p>>x;
			modify2(1,p,x);
		} else if(opt==3) {
			int l,r;
			cin>>l>>r;
			pii ret=qry1(1,l,r);
			ull val=ret.first,s=ret.second;
			if(val==s) {
				cout<<val<<"\n";
				continue;
			}
			for(int i=63;i>=0;i--){
                //cout << val << ' ' << s << ' ';
				if(((s>>i)&1)&&(!((val>>i)&1))) {
					int p=qry2(1,l,r,i);
					ull ans=inf;
					if(p!=l) ans&=qry1(1,l,p-1).first;
					if(p!=r) ans&=qry1(1,p+1,r).first;
					cout<<ans<<"\n";
					break;
				}
            }
		}
	}
	return 0;
}
