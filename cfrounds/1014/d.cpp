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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n; cin >> n;
    string s; cin >> s;
    bool flag = false;
    forn(i, 1, n){
        if(s[i]!=s[i-1]){
            flag = true;
        } 
    }
    if(!flag){
        cout << -1 << nl;
        return;
    }

    lli is = 0, ls = 0, ts = 0;
    lli c1s = 0, c2s = 0, c3s = 0;
    forn(i, 0, n){
        if(s[i]=='L') ls++;
        if(s[i]=='I') is++;
        if(s[i]=='T') ts++;
    }
    char c1, c2, c3;
    if(ls <= is && ts<=is){
        c3 = 'I';
        c3s = is;
        if(ls<=ts){
            c2 = 'T';
            c2s = ts;
            c1 = 'L';
            c1s = ls;
        }
        else{
            c2 = 'L';
            c2s = ls;
            c1 = 'T';
            c1s = ts;
        }
    }
    else if(is<=ls && ts<=ls){
        c3 = 'L';
        c3s = ls;
        if(ts<=is){
            c2 = 'I';
            c2s = is;
            c1 = 'T';
            c1s = ts;
        }
        else{
            c2 = 'T';
            c2s = ts;
            c1 = 'I';
            c1s = is;
        }
    }
    else if(is<=ts && ls<=ts){
        c3 = 'T';
        c3s = ts;
        if(ls<=is){
            c2 = 'I';
            c2s = is;
            c1 = 'L';
            c1s = ls;
        }
        else{
            c2 = 'L';
            c2s = ls;
            c1 = 'I';
            c1s = is;
        }
    }

    vlli ops;

    flag = true;
    while(flag == true){
        if(c1s==c3s && c2s==c3s){
            flag = false;
            break;
        } 

        flag = false;
        forn(i, 0, s.size()-1){
            //cout << "Xd";
            if(c1s < c3s){
                if(s[i]!=s[i+1] && ((s[i] == c2 && s[i+1] == c3) || (s[i] == c3 && s[i+1] == c2))){
                    ops.pb(i+1);
                    s.insert(s.begin()+i+1, c1);
                    c1s++;
                    flag = true;
                    continue;
                }
            }
            if(c2s < c3s){
                if(s[i]!=s[i+1] && ((s[i] == c1 && s[i+1] == c3) || (s[i] == c3 && s[i+1] == c1))){
                    ops.pb(i+1);
                    s.insert(s.begin()+i+1, c2);
                    c2s++;
                    flag = true;
                }
            }
        }
    }
    //cout << s << nl;

    while(c1s<c2s){

        flag = true;
        forn(i, 0, s.size()-1){
            if(c1s==c2s) break;

                if(s[i]!=s[i+1] && ((s[i] == c2 && s[i+1] == c3) || (s[i] == c3 && s[i+1] == c2))){
                    ops.pb(i+1);
                    s.insert(s.begin()+i+1, c1);
                    c1s++;
                }
                if(c1s==c2s) break;

                if(flag && c1s<c2s) if(s[i]!=s[i+1] && ((s[i] == c2 && s[i+1] == c1) || (s[i] == c1 && s[i+1] == c2))){
                    ops.pb(i+1);
                    s.insert(s.begin()+i+1, c3);
                    c3s++;
                    flag = false;
                }
        }
    }
    while(c2s<c3s){
        forn(i, 0, s.size()-1){
            if(c2s==c3s) break;

            if(s[i]!=s[i+1] && ((s[i] == c1 && s[i+1] == c3) || (s[i] == c3 && s[i+1] == c1))){
                ops.pb(i+1);
                s.insert(s.begin()+i+1, c2);
                c2s++;
            }
        }
    }
    while(c1s<c2s){
        forn(i, 0, s.size()-1){
            if(c1s==c2s) break;
            if(s[i]!=s[i+1] && ((s[i] == c2 && s[i+1] == c3) || (s[i] == c3 && s[i+1] == c2))){
                ops.pb(i+1);
                s.insert(s.begin()+i+1, c1);
                c1s++;
            }
        }
    }
    //cout << s << nl;

    cout << ops.size() << nl;
    forn(i, 0, ops.size()) cout << ops[i] << ' ';
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}