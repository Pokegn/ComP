#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

double gss(double a, double b, double (*f)(double)){
    double r = (sqrt(5)-1)/2, eps = 1e-7;
    double x1 = b - r*(b-a), x2 = a+r*(b-a);
    double f1 = f(x1), f2 = f(x2);
    while(b-a > eps){
        if(f1<f2){
            b = x2; x2 = x1; f2 = f1;
            f1 = b-r*(b-a); f1 = f(x1);
        }
        else{
            a = x1; x1 = x2; f1 = f2;
            x2 = a+r*(b-a); f2 = f(x2);
        }
    }
    return a;
}

double absdotp(double a, double b, double c, double d){
    double ret = a*(-c) + b*d;
    if(ret < 0) ret*=-1.0;
    return ret;
}

void solve(){
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}