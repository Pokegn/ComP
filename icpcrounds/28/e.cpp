#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n;
    int a;
    string s;
    cin >> s;
    a++;
    while(s[0]>='A'){
        cin >> s;
        a++;
    }
    a--;
    n = stoi(s);
    vector<string> names(n);
    //cout << n*2 << endl;
    for(int i=0; i<n; i++) cin >> names[i];
    //return;
    
    vector<int> elegido (n, 0);
    vector<int> team1;
    vector<int> team2;
    int turno = 1;

    int curr = 0;
    for(int i=n; i>=1; i--){
        while(elegido[curr] == 1){
            curr++;
            curr%=n;
            //cout << "xd";
        }
        int aumento = a%i;
        if(aumento == 0) aumento = i;
        for(int j=0; j<aumento-1; j++){
            curr++; curr%=n;
            while(elegido[curr] == 1){
                curr++;
                curr%=n;
                //cout << "xd";
            } 
        }
        elegido[curr] = 1;
        if(turno == 1){
            team1.push_back(curr);
        }            
        else team2.push_back(curr);
        turno*=-1;
    }

    cout << team1.size() << endl;
    for(int i=0; i<team1.size(); i++){
        cout << names[team1[i]] << endl;
    }
    cout << team2.size() << endl;
    for(int i=0; i<team2.size(); i++){
        cout << names[team2[i]] << endl;
    }

    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}