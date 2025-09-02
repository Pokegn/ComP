#include<bits/stdc++.h>
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

bool compare(string a, string b){
    lli la = a.length();
    lli lb = b.length();
    if(la!= lb) return a.length() < b.length();
    return a<b;
}

void solve(){
    lli n,q; cin >> n >> q;
    vector<string> todo(n, "");
    forn(i, 0, n) cin >> todo[i]; //to-do es donde voy a buscar
    vector<string> che(q, "");
    forn(i, 0, q) cin >> che[i]; //lo que voy a buscar
    vector<string> cheorig(q, "");
    forn(i, 0, q) cheorig[i] = che[i]; //el orden original de lo que voy a buscar
    sort(che.begin(), che.end(), compare);
    sort(todo.begin(), todo.end(), compare);

    vector<string> todohastaj(n, ""); //los strings de to-do pero hasta el indice

    map<string, lli> ans;
    map<string, lli> xd;

    bool flag = false;
    lli cstring = 0; //el string de che que estoy checando
    lli clen = 0; //el tamano de el que estoy checando
    lli ctodo = 0; //el menor string de todo que checo
    while(cstring < q && ctodo < n){
        //cout << "x";

        while(todo[ctodo].length() < che[cstring].length()) ctodo++;
        if(ctodo >= n) break;

        while(clen < che[cstring].length()){
            clen++;
            forn(i,ctodo,n){
                todohastaj[i]+=todo[i][clen-1];
            }
        } 
            
        xd.clear();

        forn(i, ctodo, n){
            if(todohastaj[i].length() == clen){
                xd[todohastaj[i]]++;
                //if(todohastaj[i] == "dog") cout << "XD";
            }
        }
        
        ans[che[cstring]] = xd[che[cstring]];
        cstring++;
        while(cstring <q && che[cstring].length() == che[cstring-1].length()){
            ans[che[cstring]] = xd[che[cstring]];
            cstring++;
        }
        //cout << "d";
    }
    

    forn(i, 0, n){
        if(ans.find(cheorig[i]) != ans.end()) cout << ans[cheorig[i]] << nl;
        else cout << 0 << nl;
    }

}

 
int main(){
    //cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}