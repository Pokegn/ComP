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

void solve(){
    string s;
    cin >> s; int sz = s.length();
    stack<int> signos;
    int signo = 1;
    string ans;
    rep(i, 0, sz){
        if(s[i] == '+' || s[i] == '-'){
            if(signo == 1) s[i]='-';
            else s[i] = '+';
            continue;
        }
        // if(s[i] == '-'){
        //     if(signo == 1) ans+="+";
        //     else ans+="-";
        //     continue;
        // }
        if(s[i] == '('){
            signos.push(signo);
            if(i > 0 && s[i-1] == '-'){
                //cout << "SI";
                signo *= -1;
            }
        }
        if(s[i] == ')'){
            signo = signos.top();
            signos.pop();
        }
    }
    cout << s << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}