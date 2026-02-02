#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define f first
#define s second

using namespace std;

const int C=1e5;
const int M=998244353;

ll bp(ll a, int b){
    if(b==0)return 1;
    if(b%2)return bp(a,b-1)*a%M;
    ll aux = bp(a,b/2);
    return aux*aux%M;
}

int info[4]={1,1,2,2};

int info2[7]={0,0,2,3,4,3,3};

bool is_prime(int a){
    if(a==0 || a==1)return 1;
    for(int i=2;i*i<=a;i++)if(a%i==0)return 1;
    return 0;
}

bool prt(ll a){
    if(a==0)return 0;
    if((a%10)%3)return 1;
    return prt(a/10);
}
void brut(){
    vector<ll>res;

    unordered_map<ll,bool>vis;
    unordered_map<ll,bool>m[10];
    vector<int>dig={0,1,4,6,8,9};

    for(auto i: dig)m[0][i]=0, vis[i]=1;

    for(int i=1;i<10;i++){
        for(auto v:m[i-1]){
            if(v.f==0)continue;
            for(auto d:dig){
                ll t=v.f*10+d;
                bool f =true;
                for(ll l=1,k=t/10;;l*=10){
                    if(vis.count(k-k%l + t%l)==0){
                        f=false;
                        break;
                    }
                    if(l>k)break;
                }
                if(f && is_prime(t)){
                    m[i][t]=1;
                    vis[t]=1;
                }
            }
        }
        cout << i<<" ";
    }
    cout<<"\n";

    for(int i=0;i<10;i++){
        for(auto v:m[i])if(v.f%2 && prt(v.f))cout<<v.f<<" ";
        cout<<"\n";
    }

}

/*
1 
91 49 
901 649 981 949 
6049 6649 9469 9081 9801 
66649 94669 66049 6004 
666049 660049 600049 
6600049 6660049 6000049  
*/


int main(){
    //fast;
    int n;

    //brut();

    cin>>n;

    ll res=0;

    res+=bp(3,n);

    res-=bp(3,n-1);

    res+=bp(4,n);
    res-=bp(4,n-1);

    res-=bp(2,n-1);

    res%=M;

    res+=M;
    res%=M;

    for(int i=1;i<=n;i++){
        if(i<=4)res+=bp(4,n-i)*info[i-1];
        if(i>1)res+=bp(4,n-i);
        res%=M;
    }

    res%=M;

    for(int i=1;i<=n;i++){
        if(i<=7)res+=bp(4,n-i)*info2[i-1];
        if(i>1)res+=bp(4,n-i);
        res%=M;
    }

    res%=M;

    for(int i=1;i<n;i++){
        ll aux=bp(4,n-i);
        aux-=bp(2,n-i);
        aux+=M;
        aux%=M;

        if(i>1){
            ll aux2=bp(3,i-1);
            aux2-=bp(3,i-2);
            aux2+=M;
            aux2%=M;
            aux*=aux2;
            aux%=M;
        }
        res+=aux;
        res%=M;
    }

    cout << res % M<<"\n";

}