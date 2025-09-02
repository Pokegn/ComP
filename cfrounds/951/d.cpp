#include <bits/stdc++.h>
using namespace std;
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
    int n, k; cin >> n >> k;
    lli left, right;
    left =0 ;
    right = 1;
    bool roto = 0;
    bool bin = 0;
    string s; cin >> s;
    lli p, q;

    while(!roto){
        if(right>=n){
            if(right - left == k ) bin = 1;
            break;
        }
        if(s[right] == s[right-1]){
            right++;
            continue;
        }

        if(right - left == k){ // si cambia de color y todo bien
            right++;
            left = right-1;
        }
        else{
            if(right - left < k){
                p = right;
                break;
            }

            if(right - left > k){
                p = right - k;
                break;
            }
        }
    }

    if(right>=n){
        if(bin == 1){
            cout << n << nl;
        }
        else cout << "-1" << nl;
        return;
    }
    //cout << p << ' ';


    vector<char> b(n);
    forn(i, p, n){
        b[i-p] = s[i];
    }
    forn(i, 0, p){
        b[n-i-1] = s[i];
    }
    lli count = 1;
    forn(i, 1, n){
        if(count >k){ //mas  de k iguales
            cout << "-1" << nl;
            return;
        }
        if(i-1 >=0 && b[i] == b[i-1]){
            count++;
        }
        else{
            if(count !=k){ //menos de k iguales
                cout << "-1" << nl;
                return;
            }
            else{
                count = 1;
                continue;
            }
        }

    }  


    if(count != k) cout << "-1" << nl;
    else cout << p << nl;


}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}