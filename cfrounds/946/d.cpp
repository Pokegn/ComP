#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
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

void solve(){
    lli n; cin >> n;
    string s; cin >> s;
    vlli a(4, 0); //0 es N, 1 es E, 2 es S y 3 es W
    forn(i, 0, n){
        if(s[i] == 'N') a[0]++;
        if(s[i] == 'E') a[1]++;
        if(s[i] == 'S') a[2]++;
        if(s[i] == 'W') a[3]++;
    } 

    if((a[0]+a[2])%2 !=0 || (a[1]+a[3])%2!=0){
        cout << "NO" << nl;
        return;
    }
    pair<lli, lli> H = {0,0};
    pair<lli, lli> R = {0,0};
    pair<lli, lli> obj = {(a[1]-a[3])/2, (a[0]-a[2])/2};
    string ans = "";
    lli rs= 0; lli hs = 0;
    //cout << obj.first << ' ' << obj.second << nl;
    //return;

    forn(i, 0, n){
        if(s[i] == 'N'){
            if(H.second >= obj.second){
                ans+='R';
                rs++;
                R.second++;
            }
            else{
                ans+='H';
                hs++;
                H.second++;
            }
            continue;
        }
        if(s[i] == 'E'){
            if(H.first >= obj.first){
                ans+='R';
                rs++;
                R.first++;
            }
            else{
                ans+='H';
                hs++;
                H.first++;
            }
            continue;
        }
        if(s[i] == 'S'){
            if(H.second <= obj.second){
                ans+='R';
                rs++;
                R.second--;
            }
            else{
                ans+='H';
                hs++;
                H.second--;
            }
            continue;
            
        }
        if(s[i] == 'W'){
            if(H.first <= obj.first){
                ans+='R';
                rs++;
                R.first--;
            }
            else{
                ans+='H';
                hs++;
                H.first--;
            }  
            continue;
            
        }
    }

    
    if(rs == 0){
        if(hs == 2){
            cout <<"NO" << nl;
            return;
        }

        if(a[0]>0 && a[2]>0){
            bool x=0; bool y=0;
            forn(i, 0, n){
                if(s[i] == 'N' && x==0){
                    ans[i] = 'R';
                    x = 1;
                }
                if(s[i] == 'S' && y==0){
                    ans[i] = 'R';
                    y = 1;
                }
            }
            //cout << "YES" << nl;
            cout << ans << nl;
            return;
        }


        else if(a[1]>0 && a[3]>0){
            bool x=0; bool y=0;
            forn(i, 0, n){
                if(s[i] == 'E' && x==0){
                    ans[i] = 'R';
                    x = 1;
                }
                if(s[i] == 'W' && y==0){
                    ans[i] = 'R';
                    y = 1;
                }
            }
            //cout << "YES" << nl;
            cout << ans << nl;
            return;
        }


        else{
            cout << "NO" << nl;
            return;
        }
    }


    if(hs == 0){
        if(rs == 2){
            cout <<"NO" << nl;
            return;
        }

        if(a[0]>0 && a[2]>0){
            bool x=0; bool y=0;
            forn(i, 0, n){
                if(s[i] == 'N' && x==0){
                    ans[i] = 'H';
                    x = 1;
                }
                if(s[i] == 'S' && y==0){
                    ans[i] = 'H';
                    y = 1;
                }
            }
            //cout << "YES" << nl;
            cout << ans << nl;
            return;
        }


        else if(a[1]>0 && a[3]>0){
            bool x=0; bool y=0;
            forn(i, 0, n){
                if(s[i] == 'E' && x==0){
                    ans[i] = 'H';
                    x = 1;
                }
                if(s[i] == 'W' && y==0){
                    ans[i] = 'H';
                    y = 1;
                }
            }
            //cout << "YES" << nl;
            cout << ans << nl;
            return;
        }


        else{
            cout << "NO" << nl;
            return;
        }
    }

    cout << ans << nl;
    return;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}