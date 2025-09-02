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
    lli  n, k;cin >> n >> k;
    lli ans=0;
    vlli a(n); forn(i, 0, n) cin >> a[i];
    map<lli, lli> indices;
    vvlli conj(n+2);
    lli x = 1;
    forn(i, 0, n){
        if(indices[a[i]%k]==0){
            indices[a[i]%k] = x;
            x++;
        }
        conj[indices[a[i]%k]].push_back(a[i]);
    }

    lli indimpar = -1;
    forn(i,1, x){
        if(conj[i].size()%2 != 0){
            if(indimpar != -1 || n%2==0){
                std::cout << -1 << nl;
                return;
            }
            else{
                indimpar = i;
            }
        }
    }

    //std::cout << conj[indimpar].size() << ' ';

    forn(i, 1, x){
        sort(conj[i].begin(), conj[i].end());
        lli sz = conj[i].size();

        if(i == indimpar){
            //cout << ans<< nl;
            
            lli minimoo = 0;
            lli minindice = 0;
            lli curr = 0;
            for(lli j = 0; j<sz-2; j+=2){
                curr+=conj[i][j+1]-conj[i][j];
                curr-=conj[i][j+2]-conj[i][j+1];
                if(curr < minimoo){
                    minindice = j+2;
                    minimoo = curr;
                }
            }
            //cout << minindice << nl;
            for(lli j = 0; j<sz-1; j+=2){
                if(j == minindice) j++;
                ans+=(conj[i][j+1]-conj[i][j])/k;
            }
            //cout << ans << nl;
            //return;
            continue;
        }

        //std::cout << "xd?";
        for(lli j = 0; j<sz-1; j+=2){
            ans+=(conj[i][j+1]-conj[i][j])/k;
        }

    }

    std::cout << ans << nl;
    return;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}