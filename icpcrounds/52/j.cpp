// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;

#define debug 0
#define ifd if (debug)

const int MAXN = 1e6+1;
int uf[MAXN];
int sizee[MAXN];
int eIzq[MAXN], eDer[MAXN];
int izq[MAXN], der[MAXN];


int uf_find(int v) {
    if (v == uf[v])
        return v;
    return uf[v] = uf_find(uf[v]);
}

void make_set(int v) {
    uf[v] = v;
    sizee[v] = 1;
    eIzq[v] = eDer[v] = izq[v] = der[v] = v;
}

void uf_join(int a, int b) {
    a = uf_find(a);
    b = uf_find(b);
    if (a != b) {
        uf[b] = a;
        sizee[a] += sizee[b];
        der[eDer[a]] = eIzq[b];
        izq[eIzq[b]] = eDer[a];
        eDer[a] = eDer[b];
    }
}


// int uf_find(int x) { 
//     ifd cout<<"vea que uf de "<<x<<" ahorita "<<uf[x]<<endl;
//     if (uf[x]<0) {
//         eIzq[x] = x, eDer[x] = x;
//         return uf[x] = x;
//     }
//     else if (uf[x]==x) return x;


//     else  uf[x] = uf_find(uf[x]); 
//     return uf[x];
// }
// bool uf_join(int x, int y){ // True sii x e y estan en != componentes


//     int l = x, r=y;
// 	x = uf_find(x); y = uf_find(y);
// 	if(x == y) return false;
	
// 	uf[x] += uf[y]; uf[y] = x; 
//     der[eDer[x]] = eIzq[y];

//     izq[eIzq[y]] = eDer[x];
//     eDer[x] = eDer[y];
//     // creo que esto no importa, pero porsiaca
//     eIzq[y] = eDer[x];

//     return true;
// }


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    ifd cout<<"holi"<<endl;
    for(int i = 0; i < n; i++) make_set(i);

    forn(i, n) {
        int l, r; cin>>l>>r;
        l--, r--;
        if (l<0) l = i;
        izq[i] = l;
        if (r<0) r = i;
        der[i] = r;
        
        uf_join(l, i), uf_join(i, r);



    }

    ifd {
        forn(i, n) {
            cout<<i<<": "<<izq[i]<<" "<<der[i]<<endl;
        }
    }


    set<int> gente;
    forn(i, n) gente.insert(uf_find(i));
    int curr =*gente.begin();
    for(int x:gente) {
        uf_join(curr, x);
        ifd {
            cout<<"joineo "<<curr<<" con "<<x<<endl;
            ifd cout<<"el izq ahora = "<<eIzq[uf_find(curr)]<<", der = "<<eDer[uf_find(curr)]<<endl;
        }

    }

    forn(i, n) {
        int l=izq[i], r = der[i];
        if (l==i) l = -1;
        if (r==i) r = -1;

        cout<<l+1<<" "<<r+1<<"\n";

    }








}