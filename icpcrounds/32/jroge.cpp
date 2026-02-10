#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int M=998244353,M2=(M+1)/2;
int lower[3000][3000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    ll res=0;
    cin>>n;
    vector<int>a(n);
    vector<ll>p2(n+1),p3(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    p2[0]=1,p3[0]=1;
    for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2%M;
    for(int i=1;i<=n;i++)p3[i]=p3[i-1]*3%M;
    for(int i=0;i<n;i++){
        lower[i][i]=i+1;
        for(int j=i+1;j<n;j++){
            lower[i][j]=lower[i][j-1];
            while(lower[i][j]<n&&a[lower[i][j]]<a[i]+a[j])lower[i][j]++;
        }
    }

    for(int i=1;i<n;i++){
        int x=lower[0][i];
        res+=p3[n-i-1]-p2[n-i-1]-p2[n-x]*(p3[x-i-1]-p2[x-i-1])%M;
        for(int j=i+1;j<x;j++){
            int y=lower[0][j];
            int z=lower[i][j];
            res+=p3[x-j-1]*(p2[n-x]-p2[y-x]+(z<n)*p2[y-x])%M*p2[j-i-1]%M;
        }
    }
    cout<<(((p3[n-1]-1)*M2-p2[n-1]+1-res)%M+M)%M<<"\n";
}