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
    map<string, string> m;
    m["RED"] = "OIO";
    m["ORANGE"] = "OOOIII";
    m["YELLOW"] = "IIIIOI";
    m["GREEN"] = "IOIII";
    m["BLUE"] = "BIII";
    m["VIOLET"] = "IIOIII";

    map<string, string> xd;
    xd["RED"] = ".RED...";                      
    xd["ORANGE"] = "ORANGE.";
    xd["YELLOW"] = "YELLOW.";
    xd["GREEN"] = "GREEN..";
    xd["BLUE"] = "BLUE...";
    xd["VIOLET"] = "VIOLET.";

    map<pair<char, int>, string> write3;
    write3[{'O',1}] = "XXX.";
    write3[{'O',2}] = "X.X.";
    write3[{'O',3}] = "X.X.";
    write3[{'O',4}] = "X.X.";
    write3[{'O',5}] = "XXX.";

    write3[{'I',1}] = "XXX.";
    write3[{'I',2}] = "XXX.";
    write3[{'I',3}] = "XXX.";
    write3[{'I',4}] = "XXX.";
    write3[{'I',5}] = "XXX.";

    write3[{'B',1}] = "XXX.";
    write3[{'B',2}] = "X.X.";
    write3[{'B',3}] = "XXX.";
    write3[{'B',4}] = "X.X.";
    write3[{'B',5}] = "XXX.";

    map<pair<char, int>, string> write4;
    write4[{'O',1}] = "XXXX.";
    write4[{'O',2}] = "X..X.";
    write4[{'O',3}] = "X..X.";
    write4[{'O',4}] = "X..X.";
    write4[{'O',5}] = "XXXX.";

    write4[{'I',1}] = "XXXX.";
    write4[{'I',2}] = "XXXX.";
    write4[{'I',3}] = "XXXX.";
    write4[{'I',4}] = "XXXX.";
    write4[{'I',5}] = "XXXX.";

    write4[{'B',1}] = "XXXX.";
    write4[{'B',2}] = "X..X.";
    write4[{'B',3}] = "XXXX.";
    write4[{'B',4}] = "X..X.";
    write4[{'B',5}] = "XXXX.";

    map<pair<char, int>, string> write5;
    write5[{'O',1}] = "XXXXX.";
    write5[{'O',2}] = "X...X.";
    write5[{'O',3}] = "X...X.";
    write5[{'O',4}] = "X...X.";
    write5[{'O',5}] = "XXXXX.";

    write5[{'I',1}] = "XXXXX.";
    write5[{'I',2}] = "XXXXX.";
    write5[{'I',3}] = "XXXXX.";
    write5[{'I',4}] = "XXXXX.";
    write5[{'I',5}] = "XXXXX.";

    write5[{'B',1}] = "XXXXX.";
    write5[{'B',2}] = "X...X.";
    write5[{'B',3}] = "XXXXX.";
    write5[{'B',4}] = "X...X.";
    write5[{'B',5}] = "XXXXX.";


    map<pair<char, int>, string> write6;
    write6[{'O',1}] = "XXXXXX.";
    write6[{'O',2}] = "X...XX.";
    write6[{'O',3}] = "X...XX.";
    write6[{'O',4}] = "X...XX.";
    write6[{'O',5}] = "XXXXXX.";

    write6[{'I',1}] = "XXXXXX.";
    write6[{'I',2}] = "XXXXXX.";
    write6[{'I',3}] = "XXXXXX.";
    write6[{'I',4}] = "XXXXXX.";
    write6[{'I',5}] = "XXXXXX.";

    write6[{'B',1}] = "XXXXXX.";
    write6[{'B',2}] = "X...XX.";
    write6[{'B',3}] = "XXXXXX.";
    write6[{'B',4}] = "X...XX.";
    write6[{'B',5}] = "XXXXXX.";

    map<pair<char, int>, string> write;
    write[{'O',1}] = "XXXXXX.";
    write[{'O',2}] = "X...XX.";
    write[{'O',3}] = "X...XX.";
    write[{'O',4}] = "X...XX.";
    write[{'O',5}] = "XXXXXX.";

    write[{'I',1}] = "XXXXXX.";
    write[{'I',2}] = "XXXXXX.";
    write[{'I',3}] = "XXXXXX.";
    write[{'I',4}] = "XXXXXX.";
    write[{'I',5}] = "XXXXXX.";

    write[{'B',1}] = "XXXXXX.";
    write[{'B',2}] = "X...XX.";
    write[{'B',3}] = "XXXXXX.";
    write[{'B',4}] = "X...XX.";
    write[{'B',5}] = "XXXXXX.";

    string c1, c2; cin >> c1 >> c2;
    c1 = m[c1];
    ll sz = c1.length();
    ll sz2 = c2.length();
    for(int j=1; j<=5; j++){ //fila
        for(int i=0; i<sz; i++){ //letra
            if(i==0){
                if(j == 1){
                    cout << c2 << ".";
                }
                else{
                    if(sz2 == 3){
                        cout << write3[{c1[i], j}];
                    }
                    else if(sz2 == 4){
                        cout << write4[{c1[i], j}];
                    }
                    else if(sz2 == 5){
                        cout << write5[{c1[i], j}];
                    }
                    else if(sz2 == 6){
                        cout << write6[{c1[i], j}];
                    }
                }
            }
            else{
                cout << write[{c1[i], j}];
            }
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    while(t--) solve();
    return 0;
}