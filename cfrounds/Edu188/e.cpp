#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<string> strings(1,"0");
vector<ll> sums(1,0);
vector<vector<int>> digitos(1, vector<int>(10, 0));

ll digit_sum(string n){
    ll ans = 0;
    int sz = n.length();
    rep(i, 0, sz){
        ans+=n[i]-'0';
    }
    return ans;
}

void solve(){
    // int n; cin >> n;
    // cout << strings[n] << endl;
    // return;
    string s; cin >> s;
    if(s.length() == 1){
        cout << s << endl;
        return;
    }
    
    ll digitsum = digit_sum(s);
    vector<int> dig(10, 0);
    int ssize = s.length();
    rep(i, 0, ssize){
        int thisdig = (int)(s[i]-'0');
        dig[thisdig]++;
    }

    rep(i, 1, 9*s.length()+1){
        if(digitsum != i + sums[i]) continue;
        //es factible que la suma de los digitos del numero original sea i
        //cout << i << endl;
        //nomas quiero que haya numeros decentes
        bool impossible = false;
        rep(j, 0, 10){
            if(digitos[i][j] > dig[j]) impossible = true;
        }
        if(impossible) continue;
        
        // rep(j, 0, 10){
        //     cout << j << ' ' << dig[j] << ' ' << digitos[i][j] << endl;
        // }
        // return;

        bool possible = true;
        if(dig[0] > digitos[i][0]){
            possible = false;
            rep(j, 1, 10){
                //cout << dig[0] << ' ' << digitos[i][0] << endl;
                if(dig[j] > digitos[i][j]) possible = true;
            }
        } 
        if(!possible) continue; //me sobran puros digitos 0
        // cout << "xd" << endl;
        // return;
        string ans = "";
        rep(j, 0, 10){
            dig[j] -= digitos[i][j];
        }
        for(int j = 9; j>=0; j--){
            rep(k, 0, dig[j]){
                ans+=to_string(j);
            }
        }
        ans+=strings[i];
        cout << ans << endl;
        return;

    }
    cout << "mame" << endl;
    return;




    // rep(i, 0, 100){
    //     cout << strings[i] << ' ' << sums[i] << endl;
    // }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);

    string s;
    ll sum;
    rep(i, 1, 900010){
        vector<int> dig(10, 0);
        s = "";
        sum = 0;
        string nstring = to_string(i);
        while(nstring.length() > 1){
            s += nstring;
            sum += digit_sum(nstring);
            nstring = to_string(digit_sum(nstring));
        }
        s+= nstring;
        sum += digit_sum(nstring);
        int ssize = s.length();
        rep(i, 0, ssize){
            int thisdig = (int)(s[i]-'0');
            dig[thisdig]++;
        }
        strings.push_back(s);
        sums.push_back(sum);
        digitos.push_back(dig);
    }

    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}